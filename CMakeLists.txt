cmake_minimum_required(VERSION 3.28.1)
project(simple_cpp_database)

set(CMAKE_CXX_STANDARD 20)

add_executable(simple_cpp_database main.cpp
        Book.h
        SaverData.cpp
        SaverData.h
        LoaderData.cpp
        LoaderData.h
        ISaver.h
        ILoader.h
        LibraryObject.h
        Magazine.cpp
        Magazine.h
        Book.cpp
        Validator.cpp
        Validator.h
        LibraryObject.cpp
)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(simple_cpp_database PRIVATE nlohmann_json::nlohmann_json)