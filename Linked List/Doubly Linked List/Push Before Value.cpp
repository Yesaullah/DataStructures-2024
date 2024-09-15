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

    // push back method
    void Push_back(int value){
        Node* newnode = new Node(value);
        // if the list is empty
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    // inserting a node before a node with given value
    void Push_before_value(int target, int value){
        if(head==nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }
        Node* current = head;
        // traversing through the list
        while(current != nullptr && current->data != target){
            current = current->next;
        }
        // if no node found with given value
        if(current==nullptr){
            cout<<"Node with value "<<target<<" not found."<<endl;
            return;
        }

        Node* newnode = new Node(value);

        if(current == head){
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else{
            newnode->next = current;
            newnode->prev = current->prev;
            current->prev->next = newnode;
            current ->prev = newnode;
        }
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
    dll.Push_back(5);
    dll.Push_back(4);
    dll.Push_back(3);
    dll.Push_back(2);
    dll.Push_back(1);

    dll.Display_list();

    dll.Push_before_value(3, 45);
    
    dll.Display_list();
}