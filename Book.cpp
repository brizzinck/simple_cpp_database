#include "Book.h"

void Book::SetData() {
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

void Book::UpdateData() {
    ChangeData("Name", Name);
    ChangeData("Author", Author);
    ChangeData("Year", Year);
    ChangeData("Price", Price);
    ChangeData("Rating", Rating);
    ChangeData("Genre", Genre);
    ChangeData("ISBN", ISBN);
}

void Book::DisplayHeaderInfo() const {
    cout << left << setw(10) << "ID" << "| "
            << setw(20) << "Name" << "| "
            << setw(20) << "Author" << "| "
            << setw(10) << "Year" << "| "
            << setw(10) << "Price" << "| "
            << setw(10) << "Rating" << "| "
            << setw(15) << "Genre" << "| "
            << setw(15) << "ISBN" << endl
            << "-------------------------------------------------------------------------"
            "-------------------------------------------------------------------------" << endl;
}

void Book::DisplayInfo() const {
    cout << left << setw(10) << Id << "| "
            << setw(20) << Name << "| "
            << setw(20) << Author << "| "
            << setw(10) << Year << "| "
            << setw(10) << Price << "| "
            << setw(10) << Rating << "| "
            << setw(15) << Genre << "| "
            << setw(15) << ISBN << endl;
}

void Book::SelfLoader(const nlohmann::basic_json<> &data) {
    Id = data["id"];
    Name = data["name"];
    Author = data["author"];
    Year = data["year"];
    ISBN = data["isbn"];
    Rating = data["rating"];
    Genre = data["genre"];
    Price = data["price"];
}

string Book::GetPath() const {
    return LibraryObject::GetPath() + "books.json";
}

string Book::GetObjectName() const {
    return "Book";
}

nlohmann::json Book::GetSaveData() const {
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
