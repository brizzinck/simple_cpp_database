#pragma once
#include <string>
#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>
#include "LibraryObject.h"

#ifndef BOOK_H
#define BOOK_H

using namespace std;

/**
 * @class Book
 * @brief Клас для представлення книги в бібліотеці.
 *
 * Зберігає основну інформацію про книгу, таку як назва, автор, рік видання, ISBN, ціна, рейтинг та жанр.
 */
class Book final : public LibraryObject {
public:
    string Name;   ///< Назва книги
    string Author; ///< Автор книги
    int Year;      ///< Рік видання книги
    string ISBN;   ///< ISBN книги
    float Price;   ///< Ціна книги
    float Rating;  ///< Рейтинг книги
    string Genre;  ///< Жанр книги

    /**
     * @brief Встановлює всі дані книги.
     */
    void SetData() override;

    /**
     * @brief Оновлює дані книги.
     */
    void UpdateData() override;

    /**
     * @brief Відображає заголовки інформації про книгу.
     */
    void DisplayHeaderInfo() const override;

    /**
     * @brief Відображає інформацію про книгу.
     */
    void DisplayInfo() const override;

    /**
     * @brief Завантажує дані книги з JSON.
     * @param data Дані у форматі JSON для завантаження.
     */
    void SelfLoader(const nlohmann::basic_json<> &data) override;

    /**
     * @brief Отримує шлях до файлу з даними про книгу.
     * @return Шлях до файлу.
     */
    string GetPath() const override;

    /**
     * @brief Отримує назву книги.
     * @return Назва об'єкта.
     */
    string GetObjectName() const override;

    /**
     * @brief Отримує дані книги для збереження у форматі JSON.
     * @return Дані книги у форматі JSON.
     */
    nlohmann::json GetSaveData() const override;

private:
    /**
     * @brief Встановлює назву книги.
     */
    void SetName();

    /**
     * @brief Встановлює автора книги.
     */
    void SetAuthor();

    /**
     * @brief Встановлює рік видання книги.
     */
    void SetYear();

    /**
     * @brief Встановлює ціну книги.
     */
    void SetPrice();

    /**
     * @brief Встановлює рейтинг книги.
     */
    void SetRating();

    /**
     * @brief Встановлює жанр книги.
     */
    void SetGenre();

    /**
     * @brief Встановлює ISBN книги.
     */
    void SetISBN();
};

#endif //BOOK_H
