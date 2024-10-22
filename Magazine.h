#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <nlohmann/json.hpp>

#include "LibraryObject.h"


class Magazine : public LibraryObject{
public:
    string Name;

    Magazine(const nlohmann::basic_json<> &data, bool display = true)
    : LibraryObject(data, display) {
        SelfLoader(data);
        if (display)
            DisplayInfo();
    }

    Magazine(const int id, const string &name)
    : Name(name) {
        Id = id;
    }
    Magazine(){}

    string GetPath() const override {
        return LibraryObject::GetPath() + "magazine.json";
    }

    void DisplayInfo() const override {
        cout << "ID: " << Id << endl;
        cout << "Name: " << Name << endl;
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
    ~Magazine() override {}
};



#endif //MAGAZINE_H
