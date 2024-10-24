#include <string>
#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>
#include "LibraryObject.h"
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book final : public LibraryObject {
public:
    string Name;
    string Author;
    int Year;
    int ISBN;
    float Price;
    float Rating;
    string Genre;

    void SetData() override;

    void UpdateData() override;

    void DisplayHeaderInfo() const override;

    void DisplayInfo() const override;

    void SelfLoader(const nlohmann::basic_json<> &data) override;

    string GetPath() const override;

    string GetObjectName() const override;

    nlohmann::json GetSaveData() const override;
};

#endif //BOOK_H
