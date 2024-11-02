#ifndef ISAVER_H
#define ISAVER_H

#include <nlohmann/json.hpp>

/**
 * @class ISaver
 * @brief Інтерфейс для збереження даних об'єкта у форматі JSON.
 */
class ISaver {
public:
    /**
     * @brief Отримує дані об'єкта у форматі JSON для збереження.
     * @return Дані об'єкта у форматі JSON.
     */
    virtual nlohmann::json GetSaveData() const = 0;
};

#endif //ISAVER_H
