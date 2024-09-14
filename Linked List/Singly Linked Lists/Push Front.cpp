#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
    Node(): data(0), next(nullptr){}
    Node(int value): data(value), next(nullptr){}
    friend class LinkedList;
};

class LinkedList{
    Node* head;
    public:
    LinkedList(): head(nullptr){}
    LinkedList(Node* n): head(n){}
    
    void Insert_at_front(const int value){
        Node* newnode = new Node(value);

        // if the list is already empty
        if(head == nullptr){
            head = newnode;
            return;
        }

        newnode->next = head; // initializing the newnode's next pointer to current first node
        head = newnode;
    }

    // display method for the list
    void display_list(){
        // checking if the list is empty
        if(head == nullptr){
            cout<<"List is empty"<<endl;
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
    LinkedList my_list;

    my_list.Insert_at_front(5);
    my_list.Insert_at_front(4);
    my_list.Insert_at_front(3);
    my_list.Insert_at_front(2);
    my_list.Insert_at_front(1);
    
    my_list.display_list();
}