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

    // method for deleting a node from the front
    void Delete_front(){
        if (head == nullptr)
        {
            cout<<"The list is empty."<<endl;
            return;
        }
        // if the list has only one node
        if(head->next == head){
            delete head;
            head = nullptr;
        }
        else{
            Node* temp = head;
            Node* current = head;
            // traversing to the last node
            while(current->next != head){
                current = current->next;
            }
            current->next = head->next; // made to point to the second node in the list as first has to be deleted
            head = head->next; // head is now the second node
            delete temp; // deleting the first node
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

    cll.Delete_front();

    cll.Display_list();
}