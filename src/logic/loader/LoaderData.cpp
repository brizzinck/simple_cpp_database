#include "LoaderData.h"
#include "SaverData.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;

// Метод для завантаження всіх даних об'єкта в консоль з файлу
void LoaderData::LoadInConsoleAllData(LibraryObject &object, string name) {
    ifstream inFile(name);  // Відкриття файлу для читання
    nlohmann::json jsonData;
    if (inFile.is_open()) {
        try {
            inFile >> jsonData;  // Спроба зчитування даних з файлу у форматі JSON
        } catch (const nlohmann::json::parse_error &error) {
            cerr << "Error parsing JSON: " << error.what() << endl;  // Повідомлення про помилку парсингу
            return;
        }
        inFile.close();  // Закриття файлу після зчитування
    } else {
        cerr << "File " << name << " does`t exist!" << endl;  // Повідомлення про помилку, якщо файл не існує
        return;
    }

    if (!jsonData.is_array()) {
        cerr << "Invalid data_impl format! A JSON array was expected!" << endl;  // Перевірка, чи є дані у форматі масиву JSON
        return;
    }
    object.DisplayHeaderInfo();  // Відображення заголовків таблиці для об'єкта
    for (const nlohmann::basic_json<> &data: jsonData) {
        object.SelfLoader(data);  // Завантаження даних об'єкта з JSON
        object.DisplayInfo();  // Відображення інформації про об'єкт
    }
}

// Метод для завантаження даних об'єкта за індексом в консоль
bool LoaderData::LoadInConsoleDataByIndex(LibraryObject &object, int index) {
    ifstream inFile(object.GetPath());  // Відкриття файлу з даними об'єкта
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        try {
            inFile >> jsonData;  // Спроба зчитування даних з файлу у форматі JSON
        } catch (const nlohmann::json::parse_error &error) {
            cerr << "Error parsing JSON: " << error.what() << endl;  // Повідомлення про помилку парсингу
            return false;
        }
        inFile.close();  // Закриття файлу після зчитування
    } else {
        cerr << "File " << object.GetPath() << " does`t exist!" << endl;  // Повідомлення про помилку, якщо файл не існує
        return false;
    }

    if (!jsonData.is_array()) {
        cerr << "Invalid data_impl format! A JSON array was expected!" << endl;  // Перевірка, чи є дані у форматі масиву JSON
        return false;
    }

    bool found = false;
    for (const nlohmann::basic_json<> &item: jsonData) {
        if (item["id"] == index) {  // Пошук елемента за індексом (ідентифікатором)
            object.SelfLoader(item);  // Завантаження даних об'єкта з JSON
            object.DisplayHeaderInfo();  // Відображення заголовків таблиці для об'єкта
            object.DisplayInfo();  // Відображення інформації про об'єкт
            found = true;
            break;
        }
    }

    if (!found) {
        cerr << "Data of index " << index << " don`t found!" << endl;  // Повідомлення про те, що дані за індексом не знайдено
    }
    return found;
}
