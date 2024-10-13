#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertAtFront(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            head->prev = n;
            n->next = head;
            head = n;
        }
    }

    void printForward()
    {
        cout << "List:  ";
        Node *temp = head;
        if (head == NULL)
        {
            cout << "NULL\n";
            return;
        }
        while (temp->next != NULL)
        {
            cout << temp->data << " , ";
            temp = temp->next;
        }
        cout << temp->data << endl
             << endl;
    }
    void swap(Node *a, Node *b)
    {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node *Partition(Node *lower, Node *upper)
    {
        int pivot = upper->data;
        Node *i = lower->prev;

        for (Node *j = lower; j != upper; j = j->next)
        {
            if (j->data < pivot)
            {
                if (i == NULL)
                {
                    i = lower;
                }
                else
                {
                    i = i->next;
                }
                swap(i, j);
            }
        }

        if (i == NULL)
        {
            i = lower;
        }
        else
        {
            i = i->next;
        }
        swap(i, upper);

        return i;
    }

    void quicksort(Node *low, Node *high)
    {
        if (low != NULL && high != NULL && low != high && high != low->next)
        {
            Node *pivot = Partition(low, high);
            quicksort(low, pivot->prev);
            quicksort(pivot->next, high);
        }
    }
};
int main()
{
    DoublyLinkedList list;

    // Insert elements into the doubly linked list
    list.InsertAtFront(50);
    list.InsertAtFront(30);
    list.InsertAtFront(40);
    list.InsertAtFront(10);
    list.InsertAtFront(20);
    list.InsertAtFront(90);
    list.InsertAtFront(220);
    list.InsertAtFront(80);
    list.printForward();
    // Find the head and tail for quicksort
    Node *low = list.head;
    Node *high = list.tail;

    // Apply quicksort to the doubly linked list
    list.quicksort(low, high);
    list.printForward();

    return 0;
}
