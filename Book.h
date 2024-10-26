#pragma once
#include <string>
#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>
#include "LibraryObject.h"

#ifndef BOOK_H
#define BOOK_H

using namespace std;

// Оголошення класу Book, який є похідним від LibraryObject
class Book final : public LibraryObject {
public:
    // Поля класу Book які будуть зберігатися
    string Name; // Назва книги
    string Author; // Автор книги
    int Year; // Рік видання
    string ISBN; // ISBN книги
    float Price; // Ціна книги
    float Rating; // Рейтинг книги
    string Genre; // Жанр книги

    // Методи для роботи з даними книги
    void SetData() override; // Встановлення всіх даних книги
    void UpdateData() override; // Оновлення даних книги
    void DisplayHeaderInfo() const override; // Відображення заголовків інформації про книгу
    void DisplayInfo() const override; // Відображення інформації про книгу
    void SelfLoader(const nlohmann::basic_json<> &data) override; // Завантаження даних книги з JSON
    string GetPath() const override; // Отримання шляху до файлу
    string GetObjectName() const override; // Отримання назви об'єкта
    nlohmann::json GetSaveData() const override; // Отримання даних книги для збереження у форматі JSON

private:
    // Приватні методи для встановлення значень окремих полів
    void SetName(); // Встановлення назви книги
    void SetAuthor(); // Встановлення автора книги
    void SetYear(); // Встановлення року видання книги
    void SetPrice(); // Встановлення ціни книги
    void SetRating(); // Встановлення рейтингу книги
    void SetGenre(); // Встановлення жанру книги
    void SetISBN(); // Встановлення ISBN книги
};

#endif //BOOK_H
