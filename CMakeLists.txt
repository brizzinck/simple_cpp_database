cmake_minimum_required(VERSION 3.29)
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
)
