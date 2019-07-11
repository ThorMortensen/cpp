cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()


project(cppDojo VERSION 1.0
        DESCRIPTION "Train cpp"
        LANGUAGES CXX)

add_library(helloWorld_lib STATIC src/helloWorld/main.cpp include/helloWorld/lib.hpp)
target_include_directories(helloWorld_lib PUBLIC include)


add_executable(helloWorld two.cpp three.h)
