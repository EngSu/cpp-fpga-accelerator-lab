#pragma once
#include <cstddef>

class MemoryPool {
public:
    MemoryPool(std::size_t blockSize, std::size_t blockCount);
    ~MemoryPool();

    void* allocate();
    void deallocate(void* ptr);

private:
    struct Block {
        Block* next;
    };

    Block* freeList;
    char* pool;

    std::size_t blockSize;
    std::size_t blockCount;
};
