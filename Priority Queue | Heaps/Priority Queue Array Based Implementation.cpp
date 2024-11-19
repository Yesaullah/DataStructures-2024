#include <iostream>
#include <climits>
using namespace std;

struct Item
{
    int value;
    int priority;
};

class PriorityQueue
{
    Item queue[100000]; // array to store elements of the queue
    int size_queue;     // size of the queue, points to the last index

public:
    PriorityQueue() : size_queue(-1) {}

    void enqueue(int v, int p)
    {
        size_queue++;
        queue[size_queue].value = v;
        queue[size_queue].priority = p;
    }

    int peek()
    {
        int highestPriority = INT_MIN;
        int index = -1;

        for (int i = 0; i <= size_queue; i++)
        {
            if (highestPriority < queue[i].priority)
            {
                highestPriority = queue[i].priority;
                index = i;
            }
            else if (highestPriority == queue[i].priority && index > -1 && queue[index].value < queue[i].value)
            {
                highestPriority = queue[i].priority;
                index = i;
            }
        }
        return index;
    }

    void dequeue()
    {
        int index = peek();
        for (int i = 0; i < size_queue; i++)
        {
            queue[i] = queue[i + 1];
        }
        size_queue--;
    }

    bool isEmpty()
    {
        return size_queue == -1;
    }

    int getSize()
    {
        return size_queue + 1;
    }

    int highestPriorityValue()
    {
        int index = peek();
        return queue[index].value;
    }

    int highestPriority()
    {
        int index = peek();
        return queue[index].priority;
    }
};

int main()
{
    PriorityQueue pq;

    pq.enqueue(10, 2);
    pq.enqueue(14, 4);
    pq.enqueue(16, 4);
    pq.enqueue(12, 3);

    cout << "Element with highest priority: " << pq.highestPriorityValue() << " (Priority: " << pq.highestPriority() << ")" << endl;
    pq.dequeue();
    cout << "Element with next highest priority after dequeue: " << pq.highestPriorityValue() << " (Priority: " << pq.highestPriority() << ")" << endl;

    return 0;
}