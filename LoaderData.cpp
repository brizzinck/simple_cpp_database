#include "LoaderData.h"
#include "SaverData.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;
void LoaderData::ReadAllJSON(string name) {
    ifstream inFile(name);
    nlohmann::json jsonData;
    if (inFile.is_open()) {
        try {
            inFile >> jsonData;
        } catch (const nlohmann::json::parse_error& e) {
            cerr << "Error parsing JSON: " << e.what() << endl;
            return;
        }
        inFile.close();
    } else {
        cerr << "File" << name << " doesn`t exist!" << endl;
        return;
    }

    if (!jsonData.is_array()) {
        cerr << "Invalid data format! A JSON array was expected!" << endl;
        return;
    }

    for (const auto& item : jsonData)
        cout << item.dump() << endl;
}

void LoaderData::ReadByIndex(LibraryObject &object, int index) {
    ifstream inFile(object.GetPath());
    nlohmann::json jsonData;

    if (inFile.is_open()) {
        try {
            inFile >> jsonData;
        } catch (const nlohmann::json::parse_error& e) {
            cerr << "Error parsing JSON: " << e.what() << endl;
            return;
        }
        inFile.close();
    } else {
        cerr << "File" << object.GetPath() << " doesn`t exist!" << endl;
        return;
    }

    if (!jsonData.is_array()) {
        cerr << "Invalid data format! A JSON array was expected!" << endl;
        return;
    }

    bool found = false;
    for (const nlohmann::basic_json<> &item : jsonData)
        if (item["id"] == index) {
            object.SelfLoader(item);
            found = true;
            break;
        }

    if (!found)
        cerr << "Data of index " << index << " don`t found!" << endl;
}