#include <string>
#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>
#include "LibraryObject.h"
#include "ISaver.h"
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book final : public LibraryObject {
public:
    Book(const nlohmann::basic_json<> &data, bool display = true)
        : LibraryObject(data, display) {
        SelfLoader(data);
        if (display)
            DisplayInfo();
    }

    std::string Name;
    std::string Author;
    int Year;
    int ISBN;
    Book(const int id, const std::string &name, const std::string &author, const int year, const int isbn)
        : Name(name), Author(author), Year(year), ISBN(isbn) {
        Id = id;
    }
    Book(){}
    void SetData() override {
        cout << "Name" << endl;
        cin >> Name;
        cout << "Author" << endl;
        cin >> Author;
        cout << "Year" << endl;
        cin >> Year;
        cout << "ISBN" << endl;
        cin >> ISBN;
    }
    void UpdateData() override {
        ChangeData("Name", Name);
        ChangeData("Author", Author);
        ChangeData("Year", Year);
        ChangeData("ISBN", ISBN);
    }

    void DisplayInfo() const {
        cout << "ID: " << Id << endl;
        cout << "Name: " << Name << endl;
        cout << "Author: " << Author << endl;
        cout << "Year: " << Year << endl;
        cout << "ISBN: " << ISBN << endl;
    }

    void SelfLoader(const nlohmann::basic_json<> &data) override {
        Id = data["id"];
        Name = data["name"];
        Author = data["author"];
        Year = data["year"];
        ISBN = data["isbn"];
    }

    std::string GetPath() const override {
        return LibraryObject::GetPath() + "books.json";
    }

    nlohmann::json GetSaveData() const override {
        nlohmann::json jsonData;
        jsonData["id"] = Id;
        jsonData["name"] = Name;
        jsonData["author"] = Author;
        jsonData["year"] = Year;
        jsonData["isbn"] = ISBN;
        return jsonData;
    }
    ~Book() {}
};

#endif //BOOK_H
