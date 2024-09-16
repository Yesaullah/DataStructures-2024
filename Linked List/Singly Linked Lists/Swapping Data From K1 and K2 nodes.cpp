#include <iostream>

using namespace std;

class Node{
    int data;
    Node* next;
    public:
    Node():data(0), next(nullptr){}
    Node(int value):data(value), next(nullptr){}

    friend class LinkedList;
};

class LinkedList{
    Node* head;
    public:
    LinkedList():head(nullptr){}
    LinkedList(Node* n):head(n){}

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

    void Swap(int k1, int k2){
        Node* current = head;
        int count = 1;
        while(count<k1){
            current = current->next;
            count++;
        }
        Node* temp = head;
        int count2 = 1;
        while(count2 < k2){
            temp = temp->next;
            count2++;
        }
        int temp2;
        temp2 = current->data;
        current->data = temp->data;
        temp->data = temp2;
    }

    void display_list(){
        if(head == nullptr){
            cout<<"List is empty."<<endl;
            return;
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

    my_list.Insert_at_end(1);
    my_list.Insert_at_end(2);
    my_list.Insert_at_end(3);
    my_list.Insert_at_end(4);
    my_list.Insert_at_end(5);
    
    my_list.display_list();

    my_list.Swap(2, 4);

    my_list.display_list();
}