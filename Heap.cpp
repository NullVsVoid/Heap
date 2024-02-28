//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, February 25, 2024.
//

#include <iostream>
#include <vector>

class Heap {
   private:
    // The vector to store heap elements.
    std::vector<int> data;

    /**
     * The heapify function is a key component of heap operations. It ensures
     * that the heap property is maintained after an operation that might have
     * disrupted it. The function assumes that the binary trees rooted at left
     * and right of the index are already heapified, only the root may violate
     * the heap property. This method is used to fix the violation by swapping
     * the root with its smallest child (smaller value for a min heap) and then
     * recursively heapifying the affected subtree.
     *
     * @param index Index of the root node of the subtree to heapify.
     */
    void heapify(int index) {
        int smallest = index;       // Initialize smallest as root.
        int left = 2 * index + 1;   // Left = 2 * i + 1.
        int right = 2 * index + 2;  // Right = 2 * i + 2.

        // If left child is smaller than root.
        if (left < data.size() && data[left] < data[smallest]) {
            smallest = left;
        }

        // If right child is smaller than smallest so far.
        if (right < data.size() && data[right] < data[smallest]) {
            smallest = right;
        }

        // If smallest is not root.
        if (smallest != index) {
            // Swap the root with the smallest.
            int temp = data[index];
            data[index] = data[smallest];
            data[smallest] = temp;

            // Recursively heapify the affected sub-tree.
            heapify(smallest);
        }
    }

   public:
    /**
     * Inserts a new key into the heap.
     *
     * @param value The value to be inserted.
     */
    void insert(int value) {
        data.push_back(value);    // Add the value at the end.
        int i = data.size() - 1;  // Get the index of the newly added value.

        // Fix the min heap property if it is violated.
        while (i != 0 && data[(i - 1) / 2] > data[i]) {
            int temp = data[i];
            data[i] = data[(i - 1) / 2];
            data[(i - 1) / 2] = temp;

            i = (i - 1) / 2;
        }
    }

    /**
     * Removes and returns the minimum element from the heap.
     *
     * @return The minimum element in the heap.
     */
    int extractMin() {
        if (data.size() <= 0) return INT_MAX;
        if (data.size() == 1) {
            int temp = data[0];
            data.pop_back();
            return temp;
        }

        // Store the minimum value and remove it from the heap.
        int root = data[0];
        data[0] = data.back();
        data.pop_back();
        heapify(0);

        return root;
    }

    /**
     * Searches for a given value in the heap. This search method uses a linear
     * search to find the value in the heap. This is because the heap is
     * already a partially ordered data structure, and the search operation
     * does not require the entire heap to be traversed.
     *
     * @param value The value to search for.
     * @return True if the v alue is found, false otherwise.
     */
    bool search(int value) {
        for (int i : data)
            if (i == value) return true;

        return false;
    }

    /**
     * Sorts the elements of the heap in ascending order. This function
     * repeatedly extracts the minimum element from the heap and then adds it
     * to the end of the heap. This process is repeated until the heap is
     * empty, and the elements are sorted in ascending order.
     */
    void sortData() {
        for (int i = data.size() / 2 - 1; i >= 0; i--) {
            heapify(i);
        }

        for (int i = data.size() - 1; i >= 0; i--) {
            int temp = data[0];
            data[0] = data[i];
            data[i] = temp;

            heapify(i);
        }
    }

    /**
     * Displays the elements of the heap.
     */
    void display() {
        for (int i : data) std::cout << i << " ";

        std::cout << std::endl;
    }
};

int main() {
    Heap heap;

    // Insert elements
    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    // Display elements
    std::cout << "Display elements: ";
    heap.display();

    // Sort the heap and then display
    heap.sortData();
    std::cout << "Display elements after sorting: ";
    heap.display();

    // Search for an element
    int value = 15;
    if (heap.search(value)) {
        std::cout << "Element " << value << " found in the heap" << std::endl;
    } else {
        std::cout << "Element " << value << " not found in the heap"
                  << std::endl;
    }

    // Extract the minimum element
    std::cout << "Extracted minimum element: " << heap.extractMin()
              << std::endl;

    // Display elements
    std::cout << "Display elements: ";
    heap.display();

    return 0;
}