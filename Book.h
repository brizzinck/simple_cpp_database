#include <string>
#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>
#include "LibraryObject.h"
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

    string Name;
    string Author;
    int Year;
    int ISBN;
    float Price;
    float Rating;
    string Genre;

    Book(const int id, const string &name, const string &author, const int year, const int isbn)
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
        cout << "Price" << endl;
        cin >> Price;
        cout << "Rating" << endl;
        cin >> Rating;
        cout << "Genre" << endl;
        cin >> Genre;
        cout << "ISBN" << endl;
        cin >> ISBN;
    }
    void UpdateData() override {
        ChangeData("Name", Name);
        ChangeData("Author", Author);
        ChangeData("Year", Year);
        ChangeData("Price", Price);
        ChangeData("Rating", Rating);
        ChangeData("Genre", Genre);
        ChangeData("ISBN", ISBN);
    }

    void DisplayInfo() const {
        cout << "ID: " << Id << endl;
        cout << "Name: " << Name << endl;
        cout << "Author: " << Author << endl;
        cout << "Year: " << Year << endl;
        cout << "Price: " << Price << endl;
        cout << "Rating: " << Rating << endl;
        cout << "Genre: " << Genre << endl;
        cout << "ISBN: " << ISBN << endl;
    }

    void SelfLoader(const nlohmann::basic_json<> &data) override {
        Id = data["id"];
        Name = data["name"];
        Author = data["author"];
        Year = data["year"];
        ISBN = data["isbn"];
        Rating = data["rating"];
        Genre = data["genre"];
        Price = data["price"];
    }

    string GetPath() const override {
        return LibraryObject::GetPath() + "books.json";
    }

    nlohmann::json GetSaveData() const override {
        nlohmann::json jsonData;
        jsonData["id"] = Id;
        jsonData["name"] = Name;
        jsonData["author"] = Author;
        jsonData["year"] = Year;
        jsonData["isbn"] = ISBN;
        jsonData["rating"] = Rating;
        jsonData["price"] = Price;
        jsonData["genre"] = Genre;
        return jsonData;
    }
    ~Book() {}
};

#endif //BOOK_H
