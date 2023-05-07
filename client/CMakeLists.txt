cmake_minimum_required(VERSION 3.15)
project(MessengerClient)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)

add_executable(client
    main.cpp
    client.cpp
    user.cpp
    message.cpp
)

target_link_libraries(client
    Qt5::Widgets
    Boost::system
)
