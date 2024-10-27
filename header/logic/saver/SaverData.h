#ifndef SAVERDATA_H
#define SAVERDATA_H
#include "Book.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <filesystem>

using namespace std;

// Оголошення класу SaverData для збереження, оновлення та видалення даних бібліотечних об'єктів
class SaverData {
public:
    // Збереження даних об'єкта бібліотеки у файл
    static void Save(LibraryObject &libraryObject);

    // Щновлення даних об'єкта за індексом
    static void Update(LibraryObject &object, int index);

    // Видалення даних об'єкта за індексом
    static void Delete(LibraryObject &object, int index);
};

#endif //SAVERDATA_H