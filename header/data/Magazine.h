#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <nlohmann/json.hpp>
#include "LibraryObject.h"

using namespace std;

/**
 * @class Magazine
 * @brief Клас для представлення журналу в бібліотеці.
 *
 * Містить основну інформацію про журнал, таку як назва.
 */
class Magazine final : public LibraryObject {
public:
 string Name;  ///< Назва журналу

 /**
  * @brief Отримує назву журналу.
  * @return Назва об'єкта.
  */
 string GetObjectName() const override;

 /**
  * @brief Отримує шлях до файлу з даними журналів.
  * @return Шлях до файлу.
  */
 string GetPath() const override;

 /**
  * @brief Відображає заголовки таблиці про журнал.
  */
 void DisplayHeaderInfo() const override;

 /**
  * @brief Відображає інформацію про журнал.
  */
 void DisplayInfo() const override;

 /**
  * @brief Завантажує дані журналу з JSON.
  * @param data Дані у форматі JSON для завантаження.
  */
 void SelfLoader(const nlohmann::basic_json<> &data) override;

 /**
  * @brief Отримує дані журналу для збереження у форматі JSON.
  * @return Дані журналу у форматі JSON.
  */
 nlohmann::json GetSaveData() const override;

 /**
  * @brief Встановлює дані журналу.
  */
 void SetData() override;

 /**
  * @brief Оновлює дані журналу.
  */
 void UpdateData() override;

private:
 /**
  * @brief Встановлює назву журналу.
  */
 void SetName();
};

#endif //MAGAZINE_H
