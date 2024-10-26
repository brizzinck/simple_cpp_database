#include <iostream>
#include "Book.h"
#include "LoaderData.h"
#include "Magazine.h"
#include "SaverData.h"
using namespace std;

int main() {
    // Створення об'єктів для запису та читання
    Book book{};
    Magazine magazine{};

    // Створення масиву вказівників на LibraryObject для обробки різних типів бібліотечних елементів
    LibraryObject *libraryObjects[] = {&book, &magazine};

    while (true) {
        // Відображення опцій меню
        cout << "Enter an option: " << endl
             << "1. View all data" << endl
             << "2. Add data" << endl
             << "3. View data of index" << endl
             << "4. Update data of index" << endl
             << "5. Delete data of index" << endl
             << "0. Exit" << endl;

        int choice = 0;
        cin >> choice;

        // Вихід з програми, якщо користувач ввів 0
        if (choice == 0)
            return 0;

        // Запит користувача, який тип даних він хоче обробляти
        cout << "Which data? " << endl;
        int i = 0;
        for (LibraryObject* &object: libraryObjects)
            cout << ++i << ". " << object->GetObjectName() << endl;
        cin >> i;

        // Запис поточного об'єкта від вводу користувача
        LibraryObject *currentObject = libraryObjects[i - 1];

        // Обробка різних опцій користувача на основі обраного пункту меню
        switch (choice) {
            case 1: {
                // Завантаження та відображення всіх даних
                LoaderData::LoadInConsoleAllData(*currentObject, currentObject->GetPath());
                break;
            }
            case 2: {
                // Додавання нових даних
                currentObject->SetData();
                SaverData::Save(*currentObject);
                break;
            }
            case 3: {
                // Перегляд конкретних даних за індексом
                cout << "How data view of index" << endl;
                int index = 0;
                cin >> index;
                LoaderData::LoadInConsoleDataByIndex(*currentObject, index);
                break;
            }
            case 4: {
                // Оновлення даних за індексом
                cout << "How data update of index" << endl;
                LoaderData::LoadInConsoleAllData(*currentObject, currentObject->GetPath());
                int index = 0;
                cin >> index;
                // Завантаження даних за індексом для перевірки їх існування перед оновленням
                if (LoaderData::LoadInConsoleDataByIndex(*currentObject, index)) {
                    currentObject->UpdateData();
                    SaverData::Update(*currentObject, index);
                }
                break;
            }
            case 5: {
                // Видалення даних за індексом
                cout << "How data of index delete?" << endl;
                LoaderData::LoadInConsoleAllData(*currentObject, currentObject->GetPath());
                int index;
                cin >> index;
                SaverData::Delete(*currentObject, index);
                break;
            }
            default:
                // Вихід з програми для будь-якого іншого вводу
                return 0;
        }
    }
}
