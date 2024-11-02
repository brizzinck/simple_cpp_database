#ifndef IOBJECT_H
#define IOBJECT_H

#include <functional>
#include <string>
#include "ILoader.h"
#include "ISaver.h"
#include <nlohmann/json.hpp>

using namespace std;

/**
 * @class LibraryObject
 * @brief Базовий клас для всіх бібліотечних об'єктів.
 *
 * Імплементує інтерфейси ISaver та ILoader для збереження і завантаження інформації.
 */
class LibraryObject : public ISaver, public ILoader {
public:
    int Id = 0;  ///< Ідентифікатор об'єкта

    /**
     * @brief Конструктор за замовчуванням.
     */
    LibraryObject() = default;

    /**
     * @brief Відображає заголовки інформації про об'єкт.
     */
    virtual void DisplayHeaderInfo() const = 0;

    /**
     * @brief Відображає інформацію про об'єкт.
     */
    virtual void DisplayInfo() const = 0;

    /**
     * @brief Завантажує дані об'єкта з JSON.
     * @param data Дані у форматі JSON для завантаження.
     */
    void SelfLoader(const nlohmann::basic_json<> &data) override = 0;

    /**
     * @brief Отримує дані об'єкта для збереження у форматі JSON.
     * @return Дані об'єкта у форматі JSON.
     */
    nlohmann::json GetSaveData() const override = 0;

    /**
     * @brief Отримує шлях до файлу.
     * @return Шлях до файлу.
     */
    virtual std::string GetPath() const;

    /**
     * @brief Отримує назву об'єкта.
     * @return Назва об'єкта.
     */
    virtual std::string GetObjectName() const;

    /**
     * @brief Встановлює дані об'єкта.
     */
    virtual void SetData() = 0;

    /**
     * @brief Оновлює дані об'єкта.
     */
    virtual void UpdateData() = 0;

    /**
     * @brief Встановлює ідентифікатор об'єкта.
     * @param id Ідентифікатор для встановлення.
     */
    void SetId(int id) {
        this->Id = id;
    }

    /**
     * @brief Змінює значення поля об'єкта.
     *
     * @tparam T Тип значення поля.
     * @param name Назва поля для зміни.
     * @param value Поточне значення поля.
     * @param setData Функція для встановлення нового значення.
     */
    template<typename T>
    static void ChangeData(const string &name, T &value, function<void()> setData);

    /**
     * @brief Віртуальний деструктор за замовчуванням.
     */
    virtual ~LibraryObject() = default;
};

#endif //IOBJECT_H
