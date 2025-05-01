cmake_minimum_required(VERSION 3.10)
project(flashcards_server)

# Явно указываем стандарт C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server main.cpp)

# Для Windows
if(WIN32)
    target_link_libraries(server PRIVATE ws2_32)
endif()