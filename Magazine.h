#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <nlohmann/json.hpp>
#include "LibraryObject.h"

// Оголошення класу Magazine, який є похідним від LibraryObject
class Magazine final : public LibraryObject {
public:
    // Поле яке буде збережено
    string Name;  // Назва журналу

    // Отримання назви об'єкта (журнал)
    string GetObjectName() const override;

    // Отримання шляху до файлу з даними журналів
    string GetPath() const override;

    // Відображення заголовків таблиці про журнал
    void DisplayHeaderInfo() const override;

    // Відображення інформації про журнал
    void DisplayInfo() const override;

    // Завантаження даних журналу з JSON
    void SelfLoader(const nlohmann::basic_json<> &data) override;

    // Отримання даних журналу для збереження у форматі JSON
    nlohmann::json GetSaveData() const override;

    // Встановлення даних журналу
    void SetData() override;

    // Оновлення даних журналу
    void UpdateData() override;

private:
    // Приватний метод для встановлення назви журналу
    void SetName();
};

#endif //MAGAZINE_H