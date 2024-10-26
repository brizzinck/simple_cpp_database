#ifndef IOBJECT_H
#define IOBJECT_H
#include <functional>
#include <string>
#include "ILoader.h"
#include "ISaver.h"

using namespace std;

// Оголошення класу LibraryObject, який є базовим класом для всіх бібліотечних об'єктів. Він імплементує два інтерфейси на збереження та завантаження інформації
class LibraryObject : public ISaver, public ILoader {
public:
    int Id = 0;  // Айді

    LibraryObject() = default;  // Конструктор за замовчуванням

    // Віртуальні методи, які повинні бути реалізовані в похідних класах
    virtual void DisplayHeaderInfo() const = 0;  // Відображення заголовків інформації про об'єкт
    virtual void DisplayInfo() const = 0;  // Відображення інформації про об'єкт
    void SelfLoader(const nlohmann::basic_json<> &data) override = 0;  // Завантаження даних об'єкта з JSON
    nlohmann::json GetSaveData() const override = 0;  // Отримання даних об'єкта для збереження у форматі JSON

    // Отримання шляху до файлу
    virtual std::string GetPath() const;

    // Отримання назви об'єкта
    virtual std::string GetObjectName() const;

    // Віртуальні методи для встановлення і оновлення даних
    virtual void SetData() = 0;  // Встановлення всіх даних об'єкта
    virtual void UpdateData() = 0;  // Оновлення даних об'єкта

    // Встановлення айді
    void SetId(int id) {
        this->Id = id;
    }

    // Дженерік метод для зміни значення поля
    template<typename T>
    static void ChangeData(const string &name, T &value, function<void()> setData);

    virtual ~LibraryObject() = default;  // Віртуальний деструктор за замовчуванням
};

#endif //IOBJECT_H
