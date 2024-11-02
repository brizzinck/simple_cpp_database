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
include_directories(header)
include_directories(header/logic/saver)
include_directories(header/logic/loader)
include_directories(header/data)
include_directories(header/logic)
include_directories(include/json/include/nlohmann)
target_include_directories(simple_cpp_database PRIVATE header)
target_include_directories(simple_cpp_database PRIVATE header/logic/saver)
target_include_directories(simple_cpp_database PRIVATE header/logic/loader)
target_include_directories(simple_cpp_database PRIVATE header/data)
target_include_directories(simple_cpp_database PRIVATE header/logic)