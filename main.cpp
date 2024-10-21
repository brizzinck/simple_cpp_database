#include <iostream>
#include "Book.h"
#include "LoaderData.h"
#include "SaverData.h"
using namespace std;

int main() {
    auto book = Book();
    auto book2 = Book();
    LibraryObject *libraryObjects[] = { &book2, &book };

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
        for (auto &lb : libraryObjects) {
            if (dynamic_cast<Book*>(lb))
                cout << ++i << " Book: " << endl;
            else
                cout << ++i << " Unknown type" << endl;
        }

        cin >> i;

        LibraryObject *currentObject = libraryObjects[i - 1];

        switch (choice) {
            case 1: {
                LoaderData::ReadAllJSON(book.GetPath());
                break;
            }
            case 2: {
                book.SetData();
                SaverData::Save(*currentObject);
                break;
            }
            case 3: {
                cout << "How data view of index" << endl;
                int index = 0;
                cin >> index;
                LoaderData::ReadByIndex(*currentObject, index);
                break;
            }
            case 4: {
                cout << "How data update of index" << endl;
                int index = 0;
                cin >> index;
                LoaderData::ReadByIndex(*currentObject, index);
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