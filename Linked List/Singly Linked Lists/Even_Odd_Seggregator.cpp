#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}

    friend class LinkedList;
};

class LinkedList
{
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    LinkedList(Node *n) : head(n) {}

    void Insert_at_end(int value)
    {
        Node *newnode = new Node(value);
        // checking if the list is empty
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        Node *current = head;
        // traversing to the end of the list
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = nullptr;
    }

    void Seggregate()
    {
        // if the list is empty
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *current = head;
        Node *evenHead = nullptr;
        Node *evenEnd = nullptr;
        Node *oddHead = nullptr;
        Node *oddEnd = nullptr;

        // traversing through the list
        while (current != nullptr)
        {
            if (current->data % 2 == 0)
            {
                // if it is the first even number in the list
                if (evenEnd == nullptr)
                {
                    evenHead = current;
                    evenEnd = current;
                }
                else
                {
                    evenEnd->next = current;
                    evenEnd = current;
                }
            }
            else
            {
                // if it is the first odd number found
                if (oddEnd == nullptr)
                {
                    oddHead = current;
                    oddEnd = current;
                }
                else
                {
                    oddEnd->next = current;
                    oddEnd = current;
                }
            }
            current = current->next;
        }
        // in case no even number found
        if (evenHead == nullptr)
        {
            head = oddHead;
        }
        else
        {
            evenEnd->next = oddHead;
            head = evenHead;
        }
        // if any odd number was found
        if (oddHead != nullptr)
        {
            oddEnd->next = nullptr;
        }
    }

    void Display_list()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

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
    LinkedList my_list;

    my_list.Insert_at_end(34);
    my_list.Insert_at_end(2);
    my_list.Insert_at_end(55);
    my_list.Insert_at_end(4);
    my_list.Insert_at_end(24);
    my_list.Insert_at_end(33);
    my_list.Insert_at_end(7);
    my_list.Insert_at_end(11);
    

    my_list.Display_list();

    my_list.Seggregate();

    my_list.Display_list();
    
    return 0;
}