#include <iostream>
#include "memory_pool.hpp"

int main()
{
    fpga_lab::MemoryPool pool(64, 3);

    void *a = pool.allocate();
    void *b = pool.allocate();
    void *c = pool.allocate();
    void *d = pool.allocate(); // should fail

    std::cout << "A: " << a << "\n";
    std::cout << "B: " << b << "\n";
    std::cout << "C: " << c << "\n";
    std::cout << "D (should be nullptr): " << d << "\n";

    if (d == nullptr)
        std::cout << "PASS: out-of-memory handled correctly\n";
    else
        std::cout << "FAIL\n";

    return 0;
}