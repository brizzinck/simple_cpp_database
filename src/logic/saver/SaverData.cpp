#include "SaverData.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;

// Збереження даних об'єкта бібліотеки у файл
void SaverData::Save(LibraryObject &libraryObject) {
    string path = libraryObject.GetPath();
    nlohmann::json jsonData;
    int lastIndex = 0;

    // Перевірка існування каталогу та створення його, якщо він не існує
    if (filesystem::path dir = filesystem::path(path).parent_path(); !exists(dir))
        create_directories(dir);

    // Відкриття файлу для читання
    ifstream inFile(path);
    if (inFile.is_open()) {
        try {
            inFile >> jsonData;  // Зчитування даних з файлу у форматі JSON
        } catch (const nlohmann::json::parse_error &error) {
            cerr << "Error parsing JSON: " << error.what() << endl;  // Повідомлення про помилку парсингу JSON
            return;
        }
        inFile.close();  // Закриття файлу після зчитування

        // Перевірка, чи дані є масивом JSON
        if (!jsonData.is_array()) {
            cerr << "Invalid data_impl format! A JSON array was expected!" << endl;
            jsonData = nlohmann::json::array();
        }

        // Пошук останнього індексу серед наявних об'єктів
        for (const auto &item : jsonData)
            if (item.contains("id") && item["id"].is_number_integer()) {
                lastIndex = max(lastIndex, item["id"].get<int>());
            }
    } else {
        // Створення нового файлу, якщо він не існує
        jsonData = nlohmann::json::array();
        ofstream outFile(path);
        if (!outFile) {
            cerr << "Error create file: " << path << endl;  // Повідомлення про помилку створення файлу
            return;
        }
        outFile << jsonData.dump(4);
        outFile.close();
        cout << "File succeed create: " << path << endl;
    }

    // Встановлення нового індексу для об'єкта
    libraryObject.SetId(lastIndex + 1);
    nlohmann::json json = libraryObject.GetSaveData();
    jsonData.push_back(json);

    // Відкриття файлу для запису оновлених даних
    ofstream outFile(path);
    if (!outFile) {
        cerr << "Error open write file: " << path << endl;  // Повідомлення про помилку відкриття файлу для запису
        return;
    }

    outFile << jsonData.dump(4);  // Запис даних у файл у форматі JSON
    cout << "Data succeed save in file " << path << " with index " << lastIndex + 1 << endl;
}

// Оновлення даних об'єкта за індексом
void SaverData::Update(LibraryObject &object, int index) {
    ifstream inFile(object.GetPath());  // Відкриття файлу для читання
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        try {
            inFile >> jsonData;  // Зчитування даних з файлу у форматі JSON
        } catch (const nlohmann::json::parse_error &error) {
            cerr << "Error parsing JSON: " << error.what() << endl;  // Повідомлення про помилку парсингу JSON
            return;
        }
        inFile.close();  // Закриття файлу після зчитування
    } else {
        cerr << "File " << object.GetPath() << " does`t exist!" << endl;  // Повідомлення про те, що файл не існує
        return;
    }

    bool updated = false;
    // Пошук елемента за індексом та його оновлення
    for (auto &item: jsonData) {
        if (item["id"] == index) {
            object.SetId(index);
            item = object.GetSaveData();
            updated = true;
            break;
        }
    }

    if (!updated) {
        cerr << "Data of index " << index << " don`t found!" << endl;  // Повідомлення про те, що дані за індексом не знайдено
        return;
    }

    // Відкриття файлу для запису оновлених даних
    ofstream outFile(object.GetPath());
    if (!outFile.is_open()) {
        cerr << "Error open write file!" << endl;  // Повідомлення про помилку відкриття файлу для запису
        return;
    }

    outFile << jsonData.dump(4);  // Запис даних у файл у форматі JSON
    outFile.close();

    cout << "Data with index " << index << " succeed push!" << endl;
    object.DisplayHeaderInfo();  // Відображення заголовків таблиці
    object.DisplayInfo();  // Відображення інформації про об'єкт
}

// Видалення даних об'єкта за індексом
void SaverData::Delete(LibraryObject &object, int index) {
    ifstream inFile(object.GetPath());  // Відкриття файлу для читання
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        try {
            inFile >> jsonData;  // Зчитування даних з файлу у форматі JSON
        } catch (const nlohmann::json::parse_error &e) {
            cerr << "Error parsing JSON: " << e.what() << endl;  // Повідомлення про помилку парсингу JSON
            return;
        }
        inFile.close();  // Закриття файлу після зчитування
    } else {
        cerr << "File " << object.GetPath() << " don`t exist!" << endl;  // Повідомлення про те, що файл не існує
        return;
    }

    bool deleted = false;
    // Пошук елемента за індексом та його видалення
    for (auto it = jsonData.begin(); it != jsonData.end(); ++it) {
        if ((*it)["id"] == index) {
            jsonData.erase(it);
            deleted = true;
            break;
        }
    }

    if (!deleted) {
        cerr << "Data of index " << index << " don`t found!" << endl;  // Повідомлення про те, що дані за індексом не знайдено
        return;
    }

    // Відкриття файлу для запису оновлених даних
    ofstream outFile(object.GetPath());
    if (!outFile.is_open()) {
        cerr << "Error open write file!" << endl;  // Повідомлення про помилку відкриття файлу для запису
        return;
    }

    outFile << jsonData.dump(4);  // Запис даних у файл у форматі JSON
    outFile.close();

    cout << "Data with index " << index << " succeed delete!" << endl;
}