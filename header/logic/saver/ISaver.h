#ifndef ISAVER_H
#define ISAVER_H
#include <nlohmann/json.hpp>

// Оголошення інтерфейсу ISaver для збереження даних у форматі JSON
class ISaver {
public:
    // Чисто віртуальний метод для отримання даних об'єкта у форматі JSON для збереження
    virtual nlohmann::json GetSaveData() const = 0;
};

#endif //ISAVER_H