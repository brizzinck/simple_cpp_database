#ifndef LOADERDATA_H
#define LOADERDATA_H
#include "Book.h"

class LoaderData {
public:
    static void ReadAllJSON(string name);
    static void ReadByIndex(LibraryObject &object, int index);
};

#endif //LOADERDATA_H

