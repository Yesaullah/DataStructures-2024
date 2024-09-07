#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}

    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // INSERTING A NODE AT THE FRONT
    void insertAtFront(int value)
    {
        Node *newnode = new Node(value);
        Node *current = head;
        // if the list is empty
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = current;
            current->prev = newnode;
            head = newnode;
        }
    }

    // INSERTING A NODE AT THE END
    void insertAtEnd(int value)
    {
        Node *newnode = new Node(value);
        Node *current = tail;
        // if the list is empty
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->prev = current;
            current->next = newnode;
            tail = newnode;
        }
    }

    // INSERTING NODE BEFORE A GIVEN VALUE
    void insertBefore(int search_value, int value)
    {
        // checking if the list is empty
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        else
        {
            Node *current = head;
            while (current != nullptr && current->data != search_value)
            {
                current = current->next;
            }
            if (current == nullptr)
            {
                cout << "The value was not found in the list." << endl;
            }
            else
            {
                Node *newnode = new Node(value);
                if (current == head)
                {
                    newnode->next = head;
                    head->prev = newnode;
                    head = newnode;
                }
                else
                {
                    newnode->next = current;
                    newnode->prev = current->prev;
                    current->prev->next = newnode;
                    current->prev = newnode;
                }
            }
        }
    }

    // INSERTING AFTER A GIVEN VALUE
    void insertAfter(int search_value, int value)
    {
        // checking if the list is empty
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr && current->data != search_value)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "The value was not found in the list." << endl;
            return;
        }
        Node *newnode = new Node(value);
        newnode->next = current->next;
        newnode->prev = current;

        if (current->next != nullptr)
        {
            current->next->prev = newnode;
        }
        else
        {
            tail = newnode;
        }

        current->next = newnode;
    }

    // DELETE NODE FROM THE HEAD
    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete temp;
        }
    }

    // DELETING FROM THE END
    void deleteTail()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        else
        {
            if (head == tail)
            {
                deleteHead();
                return;
            }
            else
            {
                Node *temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
        }
    }

    // DELETE NODE OF A PARTICULAR VALUE
    void DeleteNode(int search_value){
        Node* current = head;
        while (current != nullptr && current->data != search_value){
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Node not found in the list." << endl;
            return;
        }
        else if (current == head){
            deleteHead();
        }
        else if (current == tail){
            deleteTail();
        }
        else{
            // this sets the next of the node before the searched node to node after the searched node
            current->prev->next = current->next;
            // this sets the previous of the node after the searched node to node before the searched node
            current->next->prev = current->prev;
            delete current;
        }
    }

    // METHOD FOR DISPLAYING THE LIST
    void DisplayList(){
        if(!head){
            cout<<"The list is empty."<<endl;
            return;
        }
        Node* current = head;
        while(current != nullptr){
            cout<<current->data<<" -> ";
            current = current->next;
        }
        cout<<"nullptr"<<endl;
    }
};

int main(){
    DoublyLinkedList list;

    list.insertAtFront(5);
    list.insertAtFront(4);
    list.insertAtFront(3);
    list.insertAtFront(2);
    list.insertAtFront(1);
    list.DisplayList();

    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.DisplayList();

    list.insertAfter(3, 83);
    list.DisplayList();

    list.insertBefore(6, 38);
    list.DisplayList();

    list.deleteHead();
    list.DisplayList();

    list.deleteTail();
    list.DisplayList();

    list.DeleteNode(38);
    list.DisplayList();

    return 0;
}