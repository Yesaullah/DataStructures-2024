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

    void Insert_at_end(int value)
    {
        Node *newnode = new Node(value);
        // checking if the list is empty
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        Node *current = head;
        // traversing to the end of the list
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = nullptr;
    }

    void Delete_node_with_value(int target){
        //checking if the list is empty
        if(head == nullptr){
            cout<<"The list is already empty."<<endl;
            return;
        }

        // if the head node stores the target value
        if(head->data == target){
            Node* current = head;
            head = current->next;
            delete current;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        while(current!=nullptr && current->data != target){
            previous = current;
            current = current->next;
        }
        if(current == nullptr){
            cout<<"No node found with the target value."<<endl;
            return;
        }
        previous->next = current->next;
        delete current;
    }

    void Display_list(){
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    LinkedList my_list;

    my_list.Insert_at_end(1);
    my_list.Insert_at_end(2);
    my_list.Insert_at_end(3);
    my_list.Insert_at_end(4);
    my_list.Insert_at_end(5);

    my_list.Display_list();

    my_list.Delete_node_with_value(2);

    my_list.Display_list();
}