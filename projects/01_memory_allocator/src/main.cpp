<<<<<<< HEAD
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
=======
#include <iostream>
#include "memory_pool.h"

int main()
{
    MemoryPool pool(64, 3);

    void *a = pool.allocate();
    void *b = pool.allocate();
    void *c = pool.allocate();

    pool.deallocate(a);
    void *d = pool.allocate(); // should reuse 'a'

    std::cout << "a: " << a << "\n";
    std::cout << "d: " << d << "\n";

    if (a == d)
    {
        std::cout << "REUSE OK (correct free-list behavior)\n";
    }
    else
    {
        std::cout << "REUSE FAIL\n";
    }

    return 0;
}
>>>>>>> 7384dd9 (Improve memory pool allocator correctness and reuse test)
