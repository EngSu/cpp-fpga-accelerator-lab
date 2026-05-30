cmake_minimum_required(VERSION 3.10)
project(memory_pool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(memory_pool
    projects/01_memory_allocator/src/memory_pool.cpp
    projects/01_memory_allocator/src/main.cpp
)

target_include_directories(memory_pool PRIVATE
    projects/01_memory_allocator/include
)