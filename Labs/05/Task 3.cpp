#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int value) : data(value), next(nullptr) {}
    friend class SinglyLinkedList;
};

class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // populating the linked list
    void push_back(int value)
    {
        Node *current = head;
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newnode;
    }

    // printing the linked list
    void display_list()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr"<<endl;
    }

    // reversing linked list recursively
    Node *recursive_reverse(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *new_head = recursive_reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }

    void reverse()
    {
        head = recursive_reverse(head);
    }
};

int main()
{
    SinglyLinkedList sll;
    int n;
    cout << "Enter the number of nodes you want to form: ";
    cin >> n;

    int element;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value in the node: " << i + 1;
        cin >> element;
        sll.push_back(element);
    }

    sll.display_list();

    sll.reverse();

    sll.display_list();

    return 0;
}