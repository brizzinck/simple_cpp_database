#include <iostream>
#include "Book.h"
#include "LoaderData.h"
#include "Magazine.h"
#include "SaverData.h"

class LibraryObject;

using namespace std;

/**
 * @brief Точка входу в програму.
 *
 * Запускає меню для керування об'єктами LibraryObject.
 * @return Код завершення програми.
 */
int main() {
    // Створення об'єктів для запису та читання
    Book book{};
    Magazine magazine{};

    // Створення масиву вказівників на LibraryObject для обробки різних типів бібліотечних елементів
    LibraryObject *libraryObjects[] = {&book, &magazine};

    while (true) {
        // Відображення опцій меню
        cout << "Enter an option: " << endl
             << "1. View all data_impl" << endl
             << "2. Add data_impl" << endl
             << "3. View data_impl of index" << endl
             << "4. Update data_impl of index" << endl
             << "5. Delete data_impl of index" << endl
             << "0. Exit" << endl;

        int choice = 0;
        cin >> choice;

        // Вихід з програми, якщо користувач ввів 0
        if (choice == 0)
            return 0;

        // Запит користувача, який тип даних він хоче обробляти
        cout << "Which data_impl? " << endl;
        int i = 0;
        for (LibraryObject* &object: libraryObjects)
            cout << ++i << ". " << object->GetObjectName() << endl;
        cin >> i;

        // Запис поточного об'єкта від вводу користувача
        LibraryObject *currentObject = libraryObjects[i - 1];

        // Обробка різних опцій користувача на основі обраного пункту меню
        switch (choice) {
            case 1:
                LoaderData::LoadInConsoleAllData(*currentObject, currentObject->GetPath());
                break;
            case 2:
                currentObject->SetData();
                SaverData::Save(*currentObject);
                break;
            case 3: {
                cout << "How data_impl view of index" << endl;
                int index = 0;
                cin >> index;
                LoaderData::LoadInConsoleDataByIndex(*currentObject, index);
                break;
            }
            case 4: {
                cout << "How data_impl update of index" << endl;
                LoaderData::LoadInConsoleAllData(*currentObject, currentObject->GetPath());
                int index = 0;
                cin >> index;
                if (LoaderData::LoadInConsoleDataByIndex(*currentObject, index)) {
                    currentObject->UpdateData();
                    SaverData::Update(*currentObject, index);
                }
                break;
            }
            case 5: {
                cout << "How data_impl of index delete?" << endl;
                LoaderData::LoadInConsoleAllData(*currentObject, currentObject->GetPath());
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
