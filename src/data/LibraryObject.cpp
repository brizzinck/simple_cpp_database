#include "LibraryObject.h"
#include <iostream>
#include <functional>
#include "Validator.h"

// Дженерік метод для зміни значення поля
// name - назва поля, яке потрібно змінити
// value - поточне значення поля
// setData - функція для встановлення нового значення
template<typename T>
void LibraryObject::ChangeData(const string &name, T &value, function<void()> setData) {
    cout << name << ": " << value << endl <<
            "Change enter 1 or don`t change enter 0: " << endl;
    int change = 0;
    cin >> change;
    switch (change) {
        case 0:  // Якщо користувач не хоче змінювати значення виходимо
            break;
        case 1:  // Якщо користувач хоче змінити значення
            setData();
        break;
        default:  // У випадку некоректного вводу виходимо
            break;
    }
}

// Отримання шляху до каталогу бібліотеки
inline string LibraryObject::GetPath() const {
    return "library/";
}

// Отримання назви об'єкта
inline string LibraryObject::GetObjectName() const {
    return "LibraryObject";
}
