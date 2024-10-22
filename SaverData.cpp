#include "SaverData.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;


void SaverData::Save(LibraryObject &libraryObject) {
    string path = libraryObject.GetPath();
    nlohmann::json jsonData;
    int lastIndex = 0;

    if (filesystem::path dir = filesystem::path(path).parent_path(); !exists(dir))
        create_directories(dir);

    ifstream inFile(path);
    if (inFile.is_open()) {
        try {
            inFile >> jsonData;
        } catch (const nlohmann::json::parse_error &e) {
            cerr << "Error parsing JSON: " << e.what() << endl;
            return;
        }
        inFile.close();

        if (!jsonData.is_array()) {
            cerr << "Invalid data format! A JSON array was expected!" << endl;
            jsonData = nlohmann::json::array();
        }

        for (const auto &item : jsonData) {
            if (item.contains("id") && item["id"].is_number_integer()) {
                lastIndex = max(lastIndex, item["id"].get<int>());
            }
        }
    } else {
        jsonData = nlohmann::json::array();
        ofstream outFile(path);
        if (!outFile) {
            cerr << "Error create file: " << path << endl;
            return;
        }
        outFile << jsonData.dump(4);
        outFile.close();
        cout << "File succeed create: " << path << endl;
    }
    libraryObject.SetId(lastIndex + 1);
    nlohmann::json json = libraryObject.GetSaveData();
    jsonData.push_back(json);
    ofstream outFile(path);
    if (!outFile) {
        cerr << "Error open write file: " << path << endl;
        return;
    }

    outFile << jsonData.dump(4);
    cout << "Data succeed save in file " << path << " with index " << lastIndex + 1 << endl;
}

void SaverData::Update(LibraryObject &object, int index) {
    ifstream inFile(object.GetPath());
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        try {
            inFile >> jsonData;
        } catch (const nlohmann::json::parse_error &e) {
            cerr << "Error parsing JSON: " << e.what() << endl;
            return;
        }
        inFile.close();
    } else {
        cerr << "File " << object.GetPath() << " doesn`t exist!" << endl;
        return;
    }

    bool updated = false;
    for (auto &item: jsonData) {
        if (item["id"] == index) {
            object.SetId(index);
            item = object.GetSaveData();
            updated = true;
            break;
        }
    }

    if (!updated) {
        cerr << "Data of index " << index << " don`t found!" << endl;
        return;
    }

    ofstream outFile(object.GetPath());
    if (!outFile.is_open()) {
        cerr << "Error open write file!" << endl;
        return;
    }

    outFile << jsonData.dump(4);
    outFile.close();

    cout << "Data with index " << index << " succeed push!" << endl;
}

void SaverData::Delete(LibraryObject &object, int index) {
    ifstream inFile(object.GetPath());
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        try {
            inFile >> jsonData;
        } catch (const nlohmann::json::parse_error &e) {
            cerr << "Error parsing JSON: " << e.what() << endl;
            return;
        }
        inFile.close();
    } else {
        cerr << "File " << object.GetPath() << " don`t exist!" << endl;
        return;
    }

    bool deleted = false;
    for (auto it = jsonData.begin(); it != jsonData.end(); ++it) {
        if ((*it)["id"] == index) {
            jsonData.erase(it);
            deleted = true;
            break;
        }
    }

    if (!deleted) {
        cerr << "Data of index " << index << " don`t found!" << endl;
        return;
    }
    ofstream outFile(object.GetPath());
    if (!outFile.is_open()) {
        cerr << "Error open write file!" << endl;
        return;
    }

    outFile << jsonData.dump(4);
    outFile.close();

    cout << "Data with index " << index << " succeed push!" << endl;
}
