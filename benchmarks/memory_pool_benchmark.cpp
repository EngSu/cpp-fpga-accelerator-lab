#include <iostream>
#include <chrono>
#include <cstdlib>
#include "memory_pool.hpp"

using namespace std;
using namespace std::chrono;

static const int N = 1000000;

int main()
{
    fpga_lab::MemoryPool pool(64, N);

    // =========================
    // Warm-up phase (not measured)
    // =========================
    for (int i = 0; i < 10000; i++)
    {
        pool.allocate();
    }

    // =========================
    // Allocate benchmark
    // =========================
    void **ptrs = new void *[N];

    auto start_alloc = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        ptrs[i] = pool.allocate();
    }

    auto end_alloc = high_resolution_clock::now();

    // =========================
    // Free benchmark
    // =========================
    auto start_free = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        pool.deallocate(ptrs[i]);
    }

    auto end_free = high_resolution_clock::now();

    // =========================
    // malloc benchmark
    // =========================
    void **ptrs2 = new void *[N];

    auto start_malloc = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        ptrs2[i] = malloc(64);
    }

    auto end_malloc = high_resolution_clock::now();

    auto start_free2 = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        free(ptrs2[i]);
    }

    auto end_free2 = high_resolution_clock::now();

    // =========================
    // Results
    // =========================
    auto pool_time =
        duration_cast<microseconds>((end_alloc - start_alloc) + (end_free - start_free)).count();

    auto malloc_time =
        duration_cast<microseconds>((end_malloc - start_malloc) + (end_free2 - start_free2)).count();

    cout << "MemoryPool total time: " << pool_time << " us\n";
    cout << "malloc/free total time: " << malloc_time << " us\n";

    double speedup = (double)malloc_time / (double)pool_time;
    cout << "Speedup: " << speedup << "x\n";

    delete[] ptrs;
    delete[] ptrs2;

    return 0;
}