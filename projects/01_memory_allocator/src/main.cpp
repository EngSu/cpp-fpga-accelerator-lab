#include <iostream>
#include <cstdint>
#include "memory_pool.hpp"

static bool is_aligned(void *ptr, size_t alignment = 64)
{
    if (!ptr)
        return false;
    return (reinterpret_cast<std::uintptr_t>(ptr) % alignment) == 0;
}

int main()
{
    std::cout << "=== Memory Pool Test ===\n\n";

    fpga_lab::MemoryPool pool(64, 3);

    void *a = pool.allocate();
    void *b = pool.allocate();
    void *c = pool.allocate();

    // ----------------------------
    // HARD FAILURE CHECK (IMPORTANT)
    // ----------------------------
    if (!a || !b || !c)
    {
        std::cout << "ERROR: Allocation failed (pool not initialized correctly)\n";
        return 1;
    }

    std::cout << "A: " << a << "\n";
    std::cout << "B: " << b << "\n";
    std::cout << "C: " << c << "\n\n";

    // ----------------------------
    // OOM TEST
    // ----------------------------
    void *d = pool.allocate();

    if (d == nullptr)
        std::cout << "OOM OK\n";
    else
        std::cout << "OOM FAIL (unexpected allocation)\n";

    // ----------------------------
    // ALIGNMENT CHECK
    // ----------------------------
    std::cout << "\nAlignment:\n";
    std::cout << "A aligned: " << is_aligned(a) << "\n";
    std::cout << "B aligned: " << is_aligned(b) << "\n";
    std::cout << "C aligned: " << is_aligned(c) << "\n";

    // ----------------------------
    // REUSE TEST (critical for allocator correctness)
    // ----------------------------
    pool.deallocate(a);
    void *e = pool.allocate();

    if (!e)
    {
        std::cout << "ERROR: Reallocation failed\n";
        return 1;
    }

    std::cout << "\nA: " << a << "\n";
    std::cout << "E: " << e << "\n";

    if (a == e)
        std::cout << "REUSE OK (LIFO free-list working)\n";
    else
        std::cout << "REUSE FAIL\n";

    // ----------------------------
    // STRESS TEST
    // ----------------------------
    std::cout << "\nRunning stress test...\n";

    for (int i = 0; i < 10000; i++)
    {
        void *x = pool.allocate();
        void *y = pool.allocate();

        if (x)
            pool.deallocate(x);
        if (y)
            pool.deallocate(y);
    }

    std::cout << "Stress OK\n";

    std::cout << "\n=== Test Finished ===\n";

    return 0;
}