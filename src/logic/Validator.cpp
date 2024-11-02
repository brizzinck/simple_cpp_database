#include "Validator.h"
#include <iostream>
#include <string>
#include <functional>

using namespace std;

string Validator::GetValidatedString(const string& prompt, function<bool(const string&)> validator, const string& errorMessage) {
    string value;
    while (true) {
        cout << prompt << endl;
        for (int i = 0; i < 2; i++) {
            getline(cin, value);
            if (validator(value)) {
                return value;
            }
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << errorMessage << endl;
    }
}