cmake_minimum_required(VERSION 3.10)
<<<<<<< HEAD

project(memory_pool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
=======
project(memory_pool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
>>>>>>> 7384dd9 (Improve memory pool allocator correctness and reuse test)

add_executable(memory_pool
    projects/01_memory_allocator/src/memory_pool.cpp
    projects/01_memory_allocator/src/main.cpp
)
<<<<<<< HEAD
=======

target_include_directories(memory_pool PRIVATE
    projects/01_memory_allocator/include
)
>>>>>>> 7384dd9 (Improve memory pool allocator correctness and reuse test)
