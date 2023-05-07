cmake_minimum_required(VERSION 3.15)
project(MessengerProject)
find_package(asio)


set(CMAKE_CXX_STANDARD 17)

add_subdirectory(client)
add_subdirectory(server)
target_link_libraries(${PROJECT_NAME} asio::asio)
