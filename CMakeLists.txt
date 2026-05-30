cmake_minimum_required(VERSION 3.10)
project(memory_pool)

set(CMAKE_CXX_STANDARD 17)

add_executable(memory_pool
    projects/01_memory_allocator/src/memory_pool.cpp
    projects/01_memory_allocator/src/main.cpp
)

add_executable(memory_pool_benchmark
    benchmarks/memory_pool_benchmark.cpp
    projects/01_memory_allocator/src/memory_pool.cpp
)

target_include_directories(memory_pool PRIVATE
    projects/01_memory_allocator/include
)

target_include_directories(memory_pool_benchmark PRIVATE
    projects/01_memory_allocator/include
)