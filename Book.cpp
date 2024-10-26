#include "Book.h"
#include "LibraryObject.cpp"

// Встановлення назви книги
void Book::SetName() {
    Name = Validator::GetValidatedString(
        "Name:",
        [](const string &input) { return !input.empty(); },
        "Invalid input. Please enter a valid name.");
}

// Встановлення автора книги
void Book::SetAuthor() {
    Author = Validator::GetValidatedString(
        "Author:",
        [](const string &input) { return !input.empty(); },
        "Invalid input. Please enter a valid author name!");
}

// Встановлення року видання книги
void Book::SetYear() {
    Year = Validator::GetValidatedInput<int>(
        "Year:",
        [](const int &year) { return year >= 0 && year <= 2024; },
        "Invalid year. Please enter a valid year between 0 and 2024!");
}

// Встановлення ціни книги
void Book::SetPrice() {
    Price = Validator::GetValidatedInput<float>(
        "Price:",
        [](const float &price) { return price >= 0; },
        "Invalid price. Please enter a valid price!");
}

// Встановлення рейтингу книги
void Book::SetRating() {
    Rating = Validator::GetValidatedInput<float>(
        "Rating:",
        [](const float &rating) { return rating >= 0 && rating <= 5; },
        "Invalid rating. Please enter a rating between 0 and 5!");
}

// Встановлення жанру книги
void Book::SetGenre() {
    Genre = Validator::GetValidatedString(
        "Genre:",
        [](const string &input) { return !input.empty(); },
        "Invalid input. Please enter a valid genre!");
}

// Встановлення ISBN книги
void Book::SetISBN() {
    ISBN = Validator::GetValidatedInput<string>(
        "ISBN:",
        [](const string &input) { return input.length() == 13 && ranges::all_of(input, ::isdigit); },
        "Invalid ISBN. Please enter a 13-digit number!");
}

// Встановлення всіх даних книги
void Book::SetData() {
    SetName();
    SetAuthor();
    SetYear();
    SetPrice();
    SetRating();
    SetGenre();
    SetISBN();
}

// Оновлення даних книги
void Book::UpdateData() {
    LibraryObject::ChangeData("Name:", Name, [this]() { SetName(); });
    LibraryObject::ChangeData("Author:", Author, [this]() { SetAuthor(); });
    LibraryObject::ChangeData("Year:", Year, [this]() { SetYear(); });
    LibraryObject::ChangeData("Price:", Price, [this]() { SetPrice(); });
    LibraryObject::ChangeData("Rating:", Rating, [this]() { SetRating(); });
    LibraryObject::ChangeData("Genre:", Genre, [this]() { SetGenre(); });
    LibraryObject::ChangeData("ISBN:", ISBN, [this]() { SetISBN(); });
}

// Відображення заголовків таблиці про книгу
void Book::DisplayHeaderInfo() const {
    cout << left << setw(10) << "ID" << "| "
         << setw(15) << "Name" << "| "
         << setw(15) << "Author" << "| "
         << setw(10) << "Year" << "| "
         << setw(10) << "Price" << "| "
         << setw(10) << "Rating" << "| "
         << setw(15) << "Genre" << "| "
         << setw(15) << "ISBN" << endl
         << "------------------------------------------------------------"
            "------------------------------------------------------------" << endl;
}

// Відображення інформації про книгу
void Book::DisplayInfo() const {
    cout << left << setw(10) << Id << "| "
         << setw(15) << Name << "| "
         << setw(15) << Author << "| "
         << setw(10) << Year << "| "
         << setw(10) << Price << "| "
         << setw(10) << Rating << "| "
         << setw(15) << Genre << "| "
         << setw(15) << ISBN << endl;
}

// Завантаження даних книги з JSON
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

// Отримання шляху до файлу
string Book::GetPath() const {
    return LibraryObject::GetPath() + "books.json";
}

// Отримання назви об'єкта
string Book::GetObjectName() const {
    return "Book";
}

// Отримання даних книги для збереження у форматі JSON
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