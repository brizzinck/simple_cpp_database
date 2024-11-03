cmake_minimum_required(VERSION 3.28.1)
project(simple_cpp_database)

set(CMAKE_CXX_STANDARD 20)

add_executable(simple_cpp_database src/main.cpp
        header/data/Book.h
        src/logic/saver/SaverData.cpp
        header/logic/saver/SaverData.h
        src/logic/loader/LoaderData.cpp
        header/logic/loader/LoaderData.h
        header/logic/saver/ISaver.h
        header/logic/loader/ILoader.h
        header/data/LibraryObject.h
        src/data/Magazine.cpp
        header/data/Magazine.h
        src/data/Book.cpp
        src/logic/Validator.cpp
        header/logic/Validator.h
        src/data/LibraryObject.cpp
)

#include_directories(include/json/include/nlohmann)  тут помилка зверніть увагу в шляху

# Вказуємо директорії заголовків безпосередньо для цільового файлу замість глобального оголошення
# Переписав на використання target_include_directories замість include_directories
# Такий підхід є більш модульним і забезпечує, що шляхи до заголовків застосовуються лише
# для цілі 'simple_cpp_database', дотримуючись сучасних практик у Cmake.
target_include_directories(simple_cpp_database PRIVATE
        ${PROJECT_SOURCE_DIR}/header
        ${PROJECT_SOURCE_DIR}/header/logic/saver
        ${PROJECT_SOURCE_DIR}/header/logic/loader
        ${PROJECT_SOURCE_DIR}/header/data
        ${PROJECT_SOURCE_DIR}/header/logic
        ${PROJECT_SOURCE_DIR}/include/json/single_include
)
