#include "Magazine.h"

string Magazine::GetObjectName() const {
    return "Magazine";
}

string Magazine::GetPath() const {
    return LibraryObject::GetPath() + "magazine.json";
}

void Magazine::DisplayHeaderInfo() const {
    cout << left << setw(10) << "ID" << "| "
            << setw(20) << "Name" << "| " << endl
            << "-------------------------------------------------------------------------"
            "-------------------------------------------------------------------------" << endl;
}

void Magazine::DisplayInfo() const {
    cout << left << setw(10) << Id << "| " << setw(20) << Name << "| " << endl;
}

void Magazine::SelfLoader(const nlohmann::basic_json<> &data) {
    Id = data["id"];
    Name = data["name"];
}

nlohmann::json Magazine::GetSaveData() const {
    nlohmann::json jsonData;
    jsonData["id"] = Id;
    jsonData["name"] = Name;
    return jsonData;
}

void Magazine::SetData() {
    cout << "Name" << endl;
    cin >> Name;
}

void Magazine::UpdateData() {
    ChangeData("Name", Name);
}
