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

    // Inserting node at the end
    void Push_back(int value){
        Node* newnode = new Node(value);

        // if the list is empty
        if(head == nullptr){
            head = newnode;
            newnode->next = head;
        }
        else{
            Node* current = head;
            // traversing to the end of the list
            while(current->next != head){
                current = current->next;
            }
            // now current is the last node in the list
            newnode->next = head;
            current->next = newnode;
        }
    }

    void Display_list(){
        if(head == nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }
        Node* current = head;
        do
        {
            cout<<current->data<<" -> ";
            current = current->next;
        } while (current!=head);
        cout<<"nullptr"<<endl;
    }
};

int main(){
    CircularLinkedList cll;

    cll.Push_back(1);
    cll.Push_back(2);
    cll.Push_back(3);
    cll.Push_back(4);
    cll.Push_back(5);
    
    cll.Display_list();
}