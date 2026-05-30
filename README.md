# C++ FPGA Accelerator Lab

A hands-on C++ systems project focused on hardware-aware software design and performance-oriented experiments inspired by FPGA and AI accelerator architectures.

This repository studies how low-level software decisions affect performance characteristics such as memory bandwidth, cache behavior, alignment, and data movement costs using modern C++.

---

## 🎯 Project Goals & Architecture

This project is structured as a gradual exploration of hardware–software co-design through practical implementations and benchmarks.

### 1. Memory Management Experiments (Implemented)

Custom memory pool allocator with cache-line alignment and free-list design.  
Focus: deterministic allocation, low overhead, and predictable memory reuse behavior.

### 2. Architectural Simulation (In Progress)

C++-based exploration of compute patterns such as matrix multiplication and systolic array-style data flow models.

### 3. Runtime Concepts (Planned)

Early-stage investigation of accelerator-like execution models, including DMA-inspired data movement and scheduling concepts.

---

## 📌 Project Note

This repository is actively evolving. Each stage is implemented incrementally and validated through benchmarks and small-scale experiments.

---

## 💡 Project Philosophy

C++ is used here as a systems modeling tool to understand how software structure influences hardware-level performance behavior in FPGA and AI accelerator contexts.

---

## 📊 Benchmark Results

MemoryPool shows ~3.2× speedup compared to malloc/free for 1M fixed-size allocations.

### Key Observations:

- O(1) allocation and deallocation
- Predictable free-list behavior
- Reduced allocator overhead compared to general-purpose malloc

These results demonstrate the benefit of deterministic memory allocation for systems-level and accelerator-style workloads.

## 📊 Benchmark Results

| Allocator   | Time (1M ops) |
| ----------- | ------------- |
| MemoryPool  | 17 ms         |
| malloc/free | 55 ms         |

**Speedup:** ~3.2×
