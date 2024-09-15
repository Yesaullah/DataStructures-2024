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

    // deleting node with a particular value
    void Delete_with_value(int target){
        // if the list is empty
        if(head == nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }

        Node* current = head;

        // traversing through the loop
        while(current!=nullptr && current->data != target){
            current = current->next;
        }
        // if node with target value is not found
        if(current == nullptr){
            cout<<"Node with value "<<target<<" not found."<<endl;
            return;
        }
        // if there is only one node in the list
        if(current == head && current == tail){
            head = nullptr;
            tail = nullptr;
        }
        // if the node is at the head
        else if(current == head){
            head = head->next;
            head->prev = nullptr;
        }
        // if the node to be deleted is at the tail
        else if(current == tail){
            tail = tail->prev;
            tail->next = nullptr;
        }
        // if the node to be delete is in the middle
        else{
            Node* before = current->prev; // this points to the node before the found node
            Node* after = current->next; // this points to the node after the found node
            before->next = after; 
            after->prev = before;
        }
        delete current;
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

    dll.Delete_with_value(3);

    dll.Display_list();
}