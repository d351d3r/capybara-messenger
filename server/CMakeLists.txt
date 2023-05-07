cmake_minimum_required(VERSION 3.10)

project(messenger_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(Qt5 REQUIRED COMPONENTS Core Network)
find_package(Boost 1.66 REQUIRED COMPONENTS system)
find_package(SQLite3 REQUIRED)

set(SOURCE_FILES
    main_server.cpp
    server.cpp
)

set(HEADER_FILES
    server.hpp
)

add_executable(messenger_server ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(messenger_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(messenger_server Qt5::Core Qt5::Network common Boost::system SQLite::SQLite3)
