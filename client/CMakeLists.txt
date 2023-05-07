cmake_minimum_required(VERSION 3.10)

project(messenger_client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network)
find_package(Boost 1.66 REQUIRED COMPONENTS system)
find_package(SQLite3 REQUIRED)

set(SOURCE_FILES
    main_ui_client.cpp
    mainwindow.cpp
    client.cpp
)

set(HEADER_FILES
    mainwindow.h
    client.hpp
)

add_executable(messenger_client ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(messenger_client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(messenger_client Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network common Boost::system SQLite::SQLite3)
