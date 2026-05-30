#include "memory_pool.hpp"

MemoryPool::MemoryPool(std::size_t blockSize, std::size_t blockCount)
    : blockSize(blockSize), blockCount(blockCount)
{
    pool = new char[blockSize * blockCount];
    freeList = reinterpret_cast<Block *>(pool);

    Block *current = freeList;
    for (std::size_t i = 0; i < blockCount - 1; i++)
    {
        current->next = reinterpret_cast<Block *>(pool + (i + 1) * blockSize);
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

    Block *head = freeList;
    freeList = freeList->next;
    return head;
}

void MemoryPool::deallocate(void *ptr)
{
    if (!ptr)
        return;

    Block *block = static_cast<Block *>(ptr);
    block->next = freeList;
    freeList = block;
}