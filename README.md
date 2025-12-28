# libDSA — Systems-Level Data Structures in C++
This project documents my journey from C++ basics to advanced systems engineering, focusing on memory management, templates, and algorithmic efficiency.

## Phase 1: Linear Structures (In Progress)
Currently implementing fundamental linear containers with a focus on manual memory management (Heap vs. Stack) and amortized analysis.

### Features Implemented
1. **Custom `DynamicArray<T>` (Vector)**
  - Generic implementation using C++ Templates.
  - Manual memory allocation using `new` and `delete`.
  - Geometric expansion (doubling capacity) for amortized $O(1)$ push-back.
  - Performance benchmarked against `std::vector`.
2. **Singly Linked List**
  - Node-based memory architecture using pointers.
  - Operations: `push_front`, `push_back`, `push_middle`, and `remove`.
  - Manual pointer manipulation and list traversal.

## Tech Stack & Tools
- **Language:** C++17
- **Concepts:** Memory Pointers, Templates, Heap Management, RAII.
- **Goal:** Preparation for technical interviews and systems programming.

