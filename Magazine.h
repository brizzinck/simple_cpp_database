#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <nlohmann/json.hpp>

#include "LibraryObject.h"


class Magazine : public LibraryObject {
public:
    string Name;

    Magazine() {
    }

    string GetObjectName() const override {
        return "Magazine";
    }


    string GetPath() const override {
        return LibraryObject::GetPath() + "magazine.json";
    }

    void DisplayHeaderInfo() const override {
        cout << left << setw(10) << "ID" << "| "
                  << setw(20) << "Name" << "| " << endl
                  << "-------------------------------------------------------------------------"
                     "-------------------------------------------------------------------------" << endl;
    }

    void DisplayInfo() const override {
        cout << left << setw(10) << Id << "| " << setw(20) << Name << "| " << endl;
    }
    void SelfLoader(const nlohmann::basic_json<> &data) override {
        Id = data["id"];
        Name = data["name"];
    }

    nlohmann::json GetSaveData() const override {
        nlohmann::json jsonData;
        jsonData["id"] = Id;
        jsonData["name"] = Name;
        return jsonData;
    }

    void SetData() override {
        cout << "Name" << endl;
        cin >> Name;
    }

    void UpdateData() override {
        ChangeData("Name", Name);
    }

    ~Magazine() override {
    }
};


#endif //MAGAZINE_H
