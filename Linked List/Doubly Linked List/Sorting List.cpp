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

    //method for sorting the list
    void Sort_list(){
        Node* current = head;
        // if the list is empty
        if(head == nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }
        // traversing through the list
        while(current != nullptr){ // outer loop iterates from first node till the last
            Node* next = current->next;
            while (next != nullptr) // inner loop iterates starting from current node till the end
            {
                // if the current node's data is greater than next node's data then swappinf is done
                if(current->data > next->data){
                    int temp = current->data;
                    current->data = next->data;
                    next->data = temp;
                }
                next = next->next; // updating the next pointer
            }
            current = current->next; // updating the current pointer
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
    dll.Push_front(45);
    dll.Push_front(63);
    dll.Push_front(23);
    dll.Push_front(748);
    dll.Push_front(98);

    dll.Display_list();

    dll.Sort_list();

    dll.Display_list();
}