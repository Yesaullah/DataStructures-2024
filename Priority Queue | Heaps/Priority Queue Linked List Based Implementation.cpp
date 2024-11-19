#include <iostream>

using namespace std;

class Node
{
    int data;
    int priority;
    Node *next;

public:
    Node(int d, int p) : data(d), priority(p), next(nullptr) {}
    friend class PriorityQueue;
};

class PriorityQueue
{
    Node *head;

public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int d, int p)
    {
        Node *newnode = new Node(d, p);
        // if the list is empty or the newnode has to replace the root
        if (!head || head->priority < p)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *current = head;
            // traversing until:
            // the last node is reached
            // OR
            // a node is encountered which has a priority less than the newnode's priority
            while (current->next != nullptr && current->next->priority > p)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }

    // returns the data of the highest priority element
    int peek()
    {
        if (!head)
        {
            cout << "Queue is empty." << endl;
            return -1; // Or throw an exception
        }
        return head->data;
    }

    // the first node is deleted always
    void dequeue()
    {
        if (!head)
        {
            return;
        }
        Node *root = head;
        head = head->next;
        delete root;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    ~PriorityQueue()
    {
        while (head)
        {
            dequeue();
        }
    }
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(4, 1);
    pq.enqueue(5, 2);
    pq.enqueue(6, 3);
    pq.enqueue(7, 0);

    while (!pq.isEmpty())
    {
        cout << " " << pq.peek();
        pq.dequeue();
    }

    return 0;
}