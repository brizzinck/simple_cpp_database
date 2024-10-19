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
        typename std::enable_if<std::is_base_of<LibraryObject, T>::value>::type static Save(const T &libraryObject);

    static void Update(const LibraryObject &object, int index);

    static void Delete(LibraryObject &object, int index);
};

template<typename T>
typename std::enable_if<std::is_base_of<LibraryObject, T>::value>::type
SaverData::Save(const T &libraryObject) {
    std::string path = libraryObject.GetPath();
    nlohmann::json jsonData;
    int lastIndex = 0;

    if (std::filesystem::path dir = std::filesystem::path(path).parent_path(); !exists(dir))
        create_directories(dir);

    std::ifstream inFile(path);
    if (inFile.is_open()) {
        try {
            inFile >> jsonData;
        } catch (const nlohmann::json::parse_error &e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
            return;
        }
        inFile.close();

        if (!jsonData.is_array()) {
            cerr << "Invalid data format! A JSON array was expected!" << endl;
            jsonData = nlohmann::json::array();
        }

        for (const auto &item : jsonData) {
            if (item.contains("id") && item["id"].is_number_integer()) {
                lastIndex = std::max(lastIndex, item["id"].get<int>());
            }
        }
    } else {
        jsonData = nlohmann::json::array();
        std::ofstream outFile(path);
        if (!outFile) {
            std::cerr << "Error create file: " << path << std::endl;
            return;
        }
        outFile << jsonData.dump(4);
        outFile.close();
        std::cout << "File succeed create: " << path << std::endl;
    }
    libraryObject.SetId(lastIndex + 1);
    nlohmann::json json_book = libraryObject.GetSaveData();
    jsonData.push_back(json_book);
    std::ofstream outFile(path);
    if (!outFile) {
        std::cerr << "Error open write file: " << path << std::endl;
        return;
    }

    outFile << jsonData.dump(4);
    std::cout << "Data succeed save in file " << path << " with index " << lastIndex + 1 << std::endl;
}

#endif //SAVERDATA_H
