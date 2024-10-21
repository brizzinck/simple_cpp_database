#ifndef SAVERDATA_H
#define SAVERDATA_H
#include "Book.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <filesystem>

using namespace std;
class SaverData {
public:
    template<typename T>
        typename enable_if<is_base_of<LibraryObject, T>::value>::type static Save(T &libraryObject);

    static void Update(LibraryObject &object, int index);

    static void Delete(LibraryObject &object, int index);
};

template<typename T>
typename enable_if<is_base_of<LibraryObject, T>::value>::type
SaverData::Save(T &libraryObject) {
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
    nlohmann::json json_book = libraryObject.GetSaveData();
    jsonData.push_back(json_book);
    ofstream outFile(path);
    if (!outFile) {
        cerr << "Error open write file: " << path << endl;
        return;
    }

    outFile << jsonData.dump(4);
    cout << "Data succeed save in file " << path << " with index " << lastIndex + 1 << endl;
}

#endif //SAVERDATA_H
