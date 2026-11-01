cmake_minimum_required(VERSION 3.16)

project(Duet VERSION 1.0.0 LANGUAGES CXX)

add_library(Duet INTERFACE)
add_library(Duet::Duet ALIAS Duet)

target_compile_features(Duet INTERFACE cxx_std_11)

target_include_directories(Duet INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_executable(duet_basic examples/basic.cpp)
    target_link_libraries(duet_basic PRIVATE Duet::Duet)
endif()
