#include <iostream>
#include <vector>

using namespace std;

/*
    Min-Heap:
    - Parent node is smaller than or equal to its child nodes.
    - To get the index of the parent node: (index-1)/2
    - To get the index of the left child node: 2*index + 1
    - To get the index of the right child node: 2*index + 2
*/

class MinQueue
{
    vector<int> heap;

    // Ensures the heap property is maintained when a new element is inserted
    void heapifyUP(int index)
    {
        while (index > 0 && heap[index] < heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]); // Swap with parent if current is smaller
            index = (index - 1) / 2;                  // Move up to the parent
        }
    }

    // Ensures the heap property is maintained when an element is removed
    void heapifyDOWN(int index)
    {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int smallest = index;

        // Find the smallest among the current node and its children
        if (left_child_index < heap.size() && heap[left_child_index] < heap[smallest])
        {
            smallest = left_child_index;
        }
        if (right_child_index < heap.size() && heap[right_child_index] < heap[smallest])
        {
            smallest = right_child_index;
        }

        // Swap and recursively heapify down if necessary
        if (smallest != index)
        {
            swap(heap[smallest], heap[index]);
            heapifyDOWN(smallest);
        }
    }

public:
    // Adds a new element to the heap
    void enqueue(int d)
    {
        heap.push_back(d);
        heapifyUP(heap.size() - 1); // Move the element up to its correct position
    }

    // Removes the smallest element (root) from the heap
    void dequeue()
    {
        if (!heap.empty())
        {
            swap(heap[0], heap[heap.size() - 1]); // Swap root with the last element
            heap.pop_back();                      // Remove the last element
            heapifyDOWN(0);                       // Fix the position of the new root
        }
        else
        {
            cout << "Heap is empty! Cannot dequeue.\n";
        }
    }

    // Returns the smallest element (root) in the heap
    int peek()
    {
        if (!heap.empty())
        {
            return heap[0]; // The root of the heap
        }
        return -1; // Return -1 if the heap is empty
    }

    // Checks if the heap is empty
    bool isEmpty()
    {
        return heap.empty();
    }
};

int main()
{
    MinQueue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(15);
    
    // Peek at the front element (smallest element)
    cout << "Min Element: " << queue.peek() << endl; // Output: 10

    // Dequeue the front element
    queue.dequeue();

    // Peek again after dequeue
    cout << "Min Element after Dequeue: " << queue.peek() << endl; // Output: 15

    return 0;
}
