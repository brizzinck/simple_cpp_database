#ifndef LOADERDATA_H
#define LOADERDATA_H
#include "Book.h"

class LoaderData {
public:
    static void LoadInConsoleAllData(LibraryObject &object, string name);

    static void LoadInConsoleDataByIndex(LibraryObject &object, int index);
};

#endif //LOADERDATA_H
