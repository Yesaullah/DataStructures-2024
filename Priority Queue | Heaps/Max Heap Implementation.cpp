#include <iostream>
#include <vector>
using namespace std;

/*
    to get the index of the parent node: (index-1)/2
    to get the index of the left child node: 2*index + 1
    to get the index of the right child node: 2*index + 2
*/

class MaxQueue
{
    vector<int> heap; // stores the elements of the heap

    // this function ensures the heap property is maintained when a new element is inserted
    void heapifyUP(int index)
    {
        // the loop runs as long as the element is not at the root and is greater than its parent
        while (index > 0 && heap[index] > heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2; // move up to the parent index
        }
    }

    // this function ensures the heap property is maintained when an element is deleted
    void heapifyDOWN(int index)
    {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int largest = index;

        // find the largest node among the root, left child and right child
        if (left_child_index < heap.size() && heap[left_child_index] > heap[largest])
        {
            // if the left child has value greater than the current node
            largest = left_child_index;
        }
        if (right_child_index < heap.size() && heap[right_child_index] > heap[largest])
        {
            // if the right child has value greater than the current node
            largest = right_child_index;
        }

        // swap and continue heapifying down if necessary
        if (largest != index)
        {
            swap(heap[largest], heap[index]);
            heapifyDOWN(largest);
        }
    }

public:
    void enqueue(int d)
    {
        heap.push_back(d);          // element is added at the end of the heap
        heapifyUP(heap.size() - 1); // move the element up to its correct position
    }

    void dequeue()
    {
        // root is to be deleted
        if (!heap.empty())
        {
            swap(heap[0], heap[heap.size() - 1]); // swap root with the last element
            heap.pop_back();                      // the new last element is deleted
            heapifyDOWN(0);                       // fix the position of the new root
        }
    }

    // this function is used to get the value of the max element (root node) in the heap
    int peek()
    {
        if (!heap.empty())
        {
            return heap[0];
        }
        return -1;
    }

    bool isEmpty()
    {
        return heap.empty();
    }
};

int main()
{
    MaxQueue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(15);

    // Peek at the front element (highest priority element)
    cout << queue.peek() << endl; // Output: 20

    // Dequeue the front element
    queue.dequeue();

    // Peek again after dequeue
    cout << queue.peek() << endl; // Output: 15

    return 0;
}