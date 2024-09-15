#include <iostream>

using namespace std;

class Node{
    int data;
    Node* next;
    public:
    Node(): data(0), next(nullptr){}
    Node(int value): data(value), next(nullptr){}

    friend class CircularLinkedList;
};

class CircularLinkedList{
    Node* head;
    public:
    CircularLinkedList(): head(nullptr){}
    CircularLinkedList(Node* n): head(n){}

    // method for inserting a node at the front
    void Push_front(int value){
        Node* newnode = new Node(value);

        // if the list is empty
        if(head == nullptr){
            head = newnode;
            newnode->next = head;
        }
        else{
            Node* current = head;
            // traversing through the list
            while(current->next != head){
                current = current->next;
            }
            // now current is the last node in the list
            Node* temp = head;
            current->next = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    // method for displaying the list
    void Display_list(){
        // if the list is empty
        if(head == nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }
        Node* current = head;
        do
        {
            cout<<current->data<<" -> ";
            current = current->next;
        } while (current != head);
        cout<<endl;
    }
};

int main(){
    CircularLinkedList cll;

    cll.Push_front(5);
    cll.Push_front(4);
    cll.Push_front(3);
    cll.Push_front(2);
    cll.Push_front(1);
    
    cll.Display_list();
}