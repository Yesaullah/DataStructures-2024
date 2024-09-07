#include <iostream>
using namespace std;

class Node
{
    Node *next;
    Node *prev;
    int data;

public:
    Node() : next(nullptr), prev(nullptr), data(0) {}
    Node(int value) : next(nullptr), prev(nullptr), data(value) {}

    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void PushFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void sortList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            while (next != nullptr)
            {
                if (current->data > next->data)
                {
                    int temp = current->data;
                    current->data = next->data;
                    next->data = temp;
                }
                // Correctly update the next pointer
                next = next->next;
            }
            current = current->next;
        }
    }

    void displayList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.PushFront(1);
    dll.PushFront(3);
    dll.PushFront(2);
    dll.PushFront(23);
    dll.PushFront(12);

    cout<<"Unsorted List: ";
    dll.displayList();

    dll.sortList();

    cout<<"Sorted List: ";
    dll.displayList();
}