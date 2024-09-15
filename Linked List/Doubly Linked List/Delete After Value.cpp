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

    // deleting the node which comes after a node with a specific value
    void Delete_after_value(int target){
        // if the list is empty
        if(head == nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }

        Node* current = head;
        // traversing through the list
        while(current != nullptr && current->data != target){
            current = current->next;
        }

        // if node with target value not found
        if(current == nullptr){
            cout<<"Node with value "<<target<<" not found."<<endl;
            return;
        }
        // if the node found is the last node
        if(current == tail){
            cout<<"There is no node after the node with the given value."<<endl;
        }
        // Deleting the node after the target node
        Node* temp = current->next;  // The node to be deleted
        current->next = temp->next;  // Link the current node to the next of the node to be deleted

        // If the node to be deleted is not the last node
        if (temp->next != nullptr) {
            temp->next->prev = current;
        } else {
            // If the node to be deleted is the tail
            tail = current;
        }

        delete temp;
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

    dll.Delete_after_value(3);

    dll.Display_list();
}