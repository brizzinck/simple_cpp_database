#ifndef IOBJECT_H
#define IOBJECT_H
#include <iostream>
#include <string>
#include <nlohmann/json_fwd.hpp>

#include "ILoader.h"
#include "ISaver.h"

using namespace std;

class LibraryObject : public ISaver, public ILoader {
public:
    int Id;

    LibraryObject() = default;

    virtual void DisplayHeaderInfo() const = 0;

    virtual void DisplayInfo() const = 0;

    virtual void SelfLoader(const nlohmann::basic_json<> &data) override = 0;

    virtual nlohmann::json GetSaveData() const override = 0;

    virtual std::string GetPath() const {
        return "library/";
    }

    virtual std::string GetObjectName() const {
        return "LibraryObject";
    }

    virtual void SetData() = 0;

    virtual void UpdateData() = 0;

    void SetId(int id) {
        this->Id = id;
    }

    static void ChangeData(const string &name, auto &varible) {
        cout << name << ": " << varible << endl <<
                "Change enter 1 or don`t change enter 0: " << endl;
        int change = 0;
        cin >> change;
        switch (change) {
            case 0:
                break;
            case 1:
                cout << "Enter " << name << ": ";
                cin >> varible;
                break;
            default:
                break;
        }
    }

    virtual ~LibraryObject() {
    }
};

#endif //IOBJECT_H
