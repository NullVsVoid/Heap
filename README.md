# Heap Data Structure Implementation

This project implements a min-heap data structure using C++. The implementation demonstrates essential heap operations such as insertion, extraction of the minimum element, searching, sorting, and display. This implementation is a practical example of how heaps can be used in applications requiring priority queues, sorting, and efficiently finding minimum or maximum elements.

## Features

- **Insertion**: Adds a new element to the heap, maintaining the min-heap property.
- **Extract Minimum**: Removes and returns the smallest element in the heap.
- **Search**: Linearly searches for an element in the heap.
- **Sort**: Performs heap sort to arrange elements in ascending order.
- **Display**: Prints the elements of the heap to the console.

## Usage

The main function demonstrates the usage of the heap by inserting elements, displaying them, sorting, searching for an element, and extracting the minimum element.

### Compilation and Execution

Ensure you have a C++ compiler installed. Compile the source code with the following command:

```
g++ -o heap main.cpp
```

Run the compiled program:

```
./heap
```

## Implementation Details

- **Heapify**: A key operation that maintains the heap property after insertion or removal. It is applied to a node and ensures that the subtree rooted at that node is a heap.
- **Insert**: Inserts a new element at the end and then adjusts the heap by swapping elements to maintain the heap property.
- **Extract Min**: Removes the root (minimum element), replaces it with the last element, and then heapifies to maintain the heap structure.
- **Search**: Performs a linear search, demonstrating that while the heap is partially ordered, finding an arbitrary element requires traversing the structure.
- **Sort**: Applies heap sort algorithm, converting the heap into a sorted array.
