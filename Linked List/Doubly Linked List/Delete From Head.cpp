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

    // method for deleting node from the head
    void Delete_from_head(){
        //if the list is already empty
        if(head==nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }

        Node* temp = head;
        // if there is only one node in the list
        if(head == tail){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next; // the second node is now the first node
            head->prev = nullptr; // the prev pointer of the new first node is set to null 
        }
        delete temp; // deletes the node.
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

    dll.Delete_from_head();

    dll.Display_list();
}