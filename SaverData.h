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
    static void Save(LibraryObject &libraryObject);

    static void Update(LibraryObject &object, int index);

    static void Delete(LibraryObject &object, int index);
};

#endif //SAVERDATA_H
