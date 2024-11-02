#ifndef ILOADER_H
#define ILOADER_H

#include <nlohmann/json.hpp>

/**
 * @class ILoader
 * @brief Інтерфейс для завантаження даних об'єкта з JSON.
 */
class ILoader {
public:
    /**
     * @brief Завантажує дані з JSON в об'єкт.
     * @param data Дані у форматі JSON для завантаження.
     */
    virtual void SelfLoader(const nlohmann::basic_json<> &data) = 0;
};

#endif //ILOADER_H
