cmake_minimum_required(VERSION 3.10)
project(flashcards_server)

# Указываем стандарт C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем путь к заголовкам (httplib.h и другим)
include_directories(backend)

# Создаем исполняемый файл, явно указывая путь к main.cpp
add_executable(server 
    backend/main.cpp
)

# Для Windows
if(WIN32)
    target_link_libraries(server PRIVATE ws2_32)
endif()