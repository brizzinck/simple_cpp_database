#include <nlohmann/json.hpp>
#ifndef ILOADER_H
#define ILOADER_H

// Оголошення інтерфейсу ILoader для завантаження даних з JSON
class ILoader {
public:
    // Чисто віртуальний метод для завантаження даних з JSON у об'єкт
    virtual void SelfLoader(const nlohmann::basic_json<> &data) = 0;
};

#endif //ILOADER_H
