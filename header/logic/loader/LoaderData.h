#ifndef LOADERDATA_H
#define LOADERDATA_H
#include "Book.h"

/**
 * @class LoaderData
 * @brief Клас для завантаження даних об'єкта з файлу.
 */
class LoaderData {
public:
    /**
     * @brief Завантажує всі дані об'єкта з JSON файлу та виводить їх у консоль.
     *
     * @param object Об'єкт для завантаження даних.
     * @param name Ім'я файлу.
     */
    static void LoadInConsoleAllData(LibraryObject &object, string name);

    /**
     * @brief Завантажує дані об'єкта за індексом та виводить їх у консоль.
     *
     * @param object Об'єкт для завантаження даних.
     * @param index Індекс, за яким завантажуються дані.
     * @return true, якщо дані знайдено, інакше false.
     */
    static bool LoadInConsoleDataByIndex(LibraryObject &object, int index);
};


#endif //LOADERDATA_H
