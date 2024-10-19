#include "SaverData.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;

void SaverData::Update(const LibraryObject &object, int index) {
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
