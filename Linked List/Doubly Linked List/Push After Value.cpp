#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;
    public:
    Node(): data(0), next(nullptr), prev(nullptr){}
    Node(int value): data(value), next(nullptr), prev(nullptr){}

    friend class DoublyLinkedList;
};

class DoublyLinkedList{
    Node* head;
    Node* tail;
    public:
    DoublyLinkedList(): head(nullptr), tail(nullptr){}

    // Inserting a node at front
    void Push_front(int value){
        Node* newnode = new Node(value);
        // if the list is empty
        if(head==nullptr){
            head = newnode;
            tail = newnode;
        }
        else{
            Node* current = head;
            newnode->next = current;
            newnode->prev = nullptr;
            current->prev = newnode;
            head = newnode;
        }
    }

    // Inserting a node after a node with given value
    void Push_after_value(int target, int value){
        // if the list is empty
        if(head==nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }

        Node* current = head;
        // traversing through the loop
        while(current!=nullptr && current->data != target){
            current = current->next;
        }

        // if value not found
        if(current == nullptr){
            cout<<"Node with value "<<target<<" not found."<<endl;
            return;
        }
        
        Node* newnode = new Node(value);

        newnode->next = current->next;
        newnode->prev = current;

        // if the node found is not the last node
        if(current->next != nullptr){
            current->next->prev = newnode;
        }
        else{
            tail = newnode;
        }

        current->next = newnode;
    }

    // method for displaying the list
    void Display_list(){
        // if the list is empty
        if (head == nullptr){
            cout<<"The list is empty;"<<endl;
            return;
        }
        Node* current = head;
        while(current!=nullptr){
            cout<<current->data<<" -> ";
            current = current->next;
        }
        cout<<"nullptr"<<endl;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.Push_front(5);
    dll.Push_front(4);
    dll.Push_front(3);
    dll.Push_front(2);
    dll.Push_front(1);
    
    dll.Display_list();

    dll.Push_after_value(3, 75);

    dll.Display_list();
}