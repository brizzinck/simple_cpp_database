#include <iostream>
#include "Book.h"
#include "LoaderData.h"
#include "Magazine.h"
#include "SaverData.h"
using namespace std;

int main() {
    auto book = Book();
    auto magazine = Magazine();
    LibraryObject *libraryObjects[] = {&book, &magazine};

    while (true) {
        cout << "Enter an option: " << endl
                << "1. View all json data" << endl
                << "2. Add data" << endl
                << "3. View data of index" << endl
                << "4. Update data of index" << endl
                << "5. Delete data of index" << endl
                << "0. Exit" << endl;
        int choice = 0;
        cin >> choice;

        if (choice == 0)
            return 0;

        cout << "Which data? " << endl;
        int i = 0;
        for (auto &object: libraryObjects)
            cout << ++i << ". " << object->GetObjectName() << endl;
        cin >> i;

        LibraryObject *currentObject = libraryObjects[i - 1];

        switch (choice) {
            case 1: {
                LoaderData::LoadInConsoleAllData(*currentObject, currentObject->GetPath());
                break;
            }
            case 2: {
                currentObject->SetData();
                SaverData::Save(*currentObject);
                break;
            }
            case 3: {
                cout << "How data view of index" << endl;
                int index = 0;
                cin >> index;
                LoaderData::LoadInConsoleDataByIndex(*currentObject, index);
                break;
            }
            case 4: {
                cout << "How data update of index" << endl;
                int index = 0;
                cin >> index;
                LoaderData::LoadInConsoleDataByIndex(*currentObject, index);
                currentObject->UpdateData();
                SaverData::Update(*currentObject, index);
                break;
            }
            case 5: {
                cout << "How data of index delete?" << endl;
                int index;
                cin >> index;
                SaverData::Delete(*currentObject, index);
                break;
            }
            default:
                return 0;
        }
    }
}
