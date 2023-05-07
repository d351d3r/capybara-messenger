cmake_minimum_required(VERSION 3.15)
project(MessengerServer)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS system REQUIRED)

add_executable(server
    main.cpp
    server.cpp
    user.cpp
    message.cpp
)

target_link_libraries(server
    Boost::system
)
