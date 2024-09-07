#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node() : data(0), next(NULL) {}
    Node(const int d) : data(d), next(NULL) {}
    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}
    LinkedList(Node *n) : head(n) {}

    // INSERT NODE AT THE END
    void AddEnd(const int value)
    {
        Node *newnode = new Node(value);
        // checking if the list was initially empty
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newnode;
            newnode->next = nullptr;
        }
    }

    // FUNCTION TO REVERSE A SINGLY LINKED LIST
    void Reverse(){
        Node *current = head;
        Node *previous = nullptr;
        Node *temp_next = nullptr;
        while (current != nullptr){
            temp_next = current->next;
            current->next = previous;
            previous = current;
            current = temp_next;
        }
        head = previous;
    }

    // DISPLAY FUNCTION
    void DisplayList()
    {
        if (!head)
        {
            cout << "The list is empty." << endl;
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
    LinkedList list;

    // ADDING MULTIPLE NODES
    list.AddEnd(1);
    list.AddEnd(2);
    list.AddEnd(3);
    list.AddEnd(4);
    list.AddEnd(5);

    cout <<"Original List: "<<endl;
    list.DisplayList();

    list.Reverse();

    cout<<"Reversed List: "<<endl;
    list.DisplayList();

    return 0;
}