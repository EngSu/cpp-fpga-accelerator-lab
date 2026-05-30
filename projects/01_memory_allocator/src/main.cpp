#include <iostream>
#include "memory_pool.hpp"

int main()
{
    // Creating 3 blocks of 64 bytes each
    MemoryPool pool(64, 3);

    void *a = pool.allocate();
    void *b = pool.allocate();
    void *c = pool.allocate();

    // Free the first block ('a')
    pool.deallocate(a);

    // This next allocation should instantly pick up the block we just freed
    void *d = pool.allocate();

    std::cout << "Address of a: " << a << "\n";
    std::cout << "Address of d: " << d << "\n";

    if (a == d)
    {
        std::cout << "REUSE OK (correct free-list behavior)\n";
    }
    else
    {
        std::cout << "REUSE FAIL\n";
    }

    // Clean up remaining allocations before ending
    pool.deallocate(b);
    pool.deallocate(c);
    pool.deallocate(d);

    return 0;
}