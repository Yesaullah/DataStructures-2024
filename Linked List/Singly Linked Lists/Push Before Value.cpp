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

    void Insert_before_value(const int target, const int value){
        // if the list is empty
        if(head == nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }

        Node* newnode = new Node(value);

        // if the first node has the target value
        if (head->data == target) {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while(current != nullptr && current->data != target){
            previous = current;
            current = current->next;
        }

        // if the node with target value is found
        if (current != nullptr){
            previous->next = newnode;
            newnode->next = current;
        }
        else{
            cout<<"Target value not found in the list."<<endl;
            delete newnode;
        }
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

    my_list.Insert_before_value(3, 78);

    my_list.display_list();
}