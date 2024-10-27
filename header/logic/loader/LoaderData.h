#ifndef LOADERDATA_H
#define LOADERDATA_H
#include "Book.h"

// Оголошення класу LoaderData для завантаження даних бібліотечних об'єктів
class LoaderData {
public:
    // Метод для завантаження всіх даних об'єкта в консоль з файлу
    static void LoadInConsoleAllData(LibraryObject &object, string name);

    // Метод для завантаження даних об'єкта за індексом в консоль
    static bool LoadInConsoleDataByIndex(LibraryObject &object, int index);
};

#endif //LOADERDATA_H
