cmake_minimum_required(VERSION 3.10)

project(common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCE_FILES
    message.cpp
    user.cpp
)

# Header files
set(HEADER_FILES
    message.hpp
    user.hpp
)

add_library(common STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
