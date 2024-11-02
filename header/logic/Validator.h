#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <functional>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

/**
 * @class Validator
 * @brief Клас для валідації введення користувача.
 */
class Validator {
public:
    /**
     * @brief Дженерік функція для отримання валідованого вводу.
     *
     * @tparam T Тип вводу.
     * @param prompt Повідомлення для користувача.
     * @param validator Функція для перевірки, чи введення є коректним.
     * @param errorMessage Повідомлення про помилку.
     * @return Введене значення, яке пройшло перевірку.
     */
    template<typename T>
    static T GetValidatedInput(const string &prompt, function<bool(const T &)> validator, const string &errorMessage) {
        T value;
        while (true) {
            cout << prompt << endl;
            cin >> value;
            if (cin.good() && validator(value))
                break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMessage << endl;
        }
        return value;
    }

    /**
     * @brief Отримує рядок, що відповідає заданим критеріям.
     *
     * @param prompt Повідомлення для користувача.
     * @param validator Функція перевірки, яка повертає true, якщо введення є коректним.
     * @param errorMessage Повідомлення про помилку у разі невдалої перевірки.
     * @return Введений рядок, що пройшов перевірку.
     */
    static string GetValidatedString(const string &prompt, function<bool(const string &)> validator, const string &errorMessage);
};

#endif //VALIDATOR_H
