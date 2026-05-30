#include "memory_pool.hpp"
#include <iostream>
#include <cstdint>

namespace fpga_lab
{

    MemoryPool::MemoryPool(std::size_t blockSize, std::size_t blockCount)
        : blockSize(blockSize), blockCount(blockCount)
    {
        // Ensure minimum block size can store pointer
        std::size_t actualBlockSize = (blockSize < sizeof(Block)) ? sizeof(Block) : blockSize;

        // Allocate raw memory for all blocks
        pool = new char[actualBlockSize * blockCount];

        // Initialize free list
        freeList = reinterpret_cast<Block *>(pool);

        Block *current = freeList;

        for (std::size_t i = 0; i < blockCount - 1; i++)
        {
            current->next = reinterpret_cast<Block *>(
                pool + (i + 1) * actualBlockSize);
            current = current->next;
        }

        current->next = nullptr;
    }

    MemoryPool::~MemoryPool()
    {
        delete[] pool;
    }

    void *MemoryPool::allocate()
    {
        if (!freeList)
            return nullptr;

        Block *node = freeList;
        freeList = freeList->next;

        return node;
    }

    void MemoryPool::deallocate(void *ptr)
    {
        if (!ptr)
            return;

        Block *node = static_cast<Block *>(ptr);
        node->next = freeList;
        freeList = node;
    }

} // namespace fpga_lab