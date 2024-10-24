#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <nlohmann/json.hpp>

#include "LibraryObject.h"


class Magazine : public LibraryObject {
public:
    string Name;

    string GetObjectName() const override;

    string GetPath() const override;

    void DisplayHeaderInfo() const override;

    void DisplayInfo() const override;

    void SelfLoader(const nlohmann::basic_json<> &data) override;

    nlohmann::json GetSaveData() const override;

    void SetData() override;

    void UpdateData() override;
};


#endif //MAGAZINE_H
