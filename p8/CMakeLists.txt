cmake_minimum_required(VERSION 3.0)
project(pe_p8)


if(EXISTS ${CMAKE_SOURCE_DIR}/.conan/conanbuildinfo.cmake)
    include(${CMAKE_SOURCE_DIR}/.conan/conanbuildinfo.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()
conan_basic_setup()

add_compile_options(-std=c++17)
add_executable(pe_p8 main.cpp)

