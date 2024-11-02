#ifndef SAVERDATA_H
#define SAVERDATA_H
#include "Book.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <filesystem>

using namespace std;
/**
 * @class SaverData
 * @brief Клас для збереження даних об'єкта в файл.
 */
class SaverData {
public:
    /**
     * @brief Зберігає дані об'єкта в JSON файл.
     *
     * @param libraryObject Об'єкт, дані якого будуть збережені.
     */
    static void Save(LibraryObject &libraryObject);

    /**
     * @brief Оновлює дані об'єкта за індексом у файлі.
     *
     * @param object Об'єкт, що оновлюється.
     * @param index Індекс, за яким буде оновлено дані.
     */
    static void Update(LibraryObject &object, int index);

    /**
     * @brief Видаляє дані об'єкта за індексом у файлі.
     *
     * @param object Об'єкт, дані якого будуть видалені.
     * @param index Індекс, за яким видаляються дані.
     */
    static void Delete(LibraryObject &object, int index);
};

#endif //SAVERDATA_H