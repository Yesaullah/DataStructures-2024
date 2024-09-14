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

    void Insert_at_end(int value){
        Node* newnode = new Node(value);
        // checking if the list is empty
        if(head == nullptr){
            head = newnode;
            return;
        }

        Node* current = head;
        // traversing to the end of the list
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newnode;
        newnode->next = nullptr;
    }

    void Insert_after_value(const int target, const int value){
        if(head == nullptr){
            cout<<"List is empty, target value not present."<<endl;
            return;
        }
        Node* newnode = new Node(value);
        Node* current = head;
        
        while(current->data != target && current->next != nullptr){
            current = current->next;
        }
        if(current->next == nullptr){
            cout<<"Target value not found in the list."<<endl;
            return;
        }
        newnode->next = current->next;
        current->next = newnode;
    }

    void display_list(){
        if(head == nullptr){
            cout<<"The list is empty."<<endl;
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
    LinkedList my_list;

    my_list.Insert_at_end(1);
    my_list.Insert_at_end(2);
    my_list.Insert_at_end(3);
    my_list.Insert_at_end(4);
    my_list.Insert_at_end(5);

    my_list.display_list();

    my_list.Insert_after_value(3, 78);

    my_list.display_list();
}