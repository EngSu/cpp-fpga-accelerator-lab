#include <iostream>
#include "memory_pool.hpp"

int main() {
    MemoryPool pool(64, 5);

    void* a = pool.allocate();
    void* b = pool.allocate();
    void* c = pool.allocate();

    pool.deallocate(a);
    pool.deallocate(b);
    pool.deallocate(c);

    std::cout << "Allocator working\n";

    return 0;
}
