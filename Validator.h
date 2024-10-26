#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <functional>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Validator {
public:
    // Дженерік функція для отримання валідованого вводу для різних типів із користувацькою функцією валідації
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

    static string GetValidatedString
        (const string &prompt, function<bool(const string &)> validator, const string &errorMessage);
};


#endif //VALIDATOR_H
