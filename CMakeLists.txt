cmake_minimum_required(VERSION 3.10)
project(memory_pool)

set(CMAKE_CXX_STANDARD 17)

add_executable(memory_pool
    projects/01_memory_allocator/src/memory_pool.cpp
    projects/01_memory_allocator/src/main.cpp
)
