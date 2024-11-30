#include <iostream>
using namespace std;

class Node{
    string data;
    Node* next;

    public:
    Node(): data(" "), next(nullptr){}
    Node(string name): data(name), next(nullptr){}

    friend class Queue;
};

class Queue{
    Node* front;
    Node* rear;

    public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    bool isempty(){
        return front == nullptr;
    }
    
    void enqueue(string name){
        Node* newnode = new Node(name);

        if(isempty()){
            front = rear = newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
    }

    void pop(){
        if(isempty()){
            return;
        }
        Node* temp = front;
        front = front->next;

        delete temp;
    }

    void display(){
        if(isempty()){
            return;
        }
        Node* current = front;
        while(current->next != nullptr){
            cout<<current->data<<" -> ";
            current= current->next;
        }
        cout<<current->data<<endl;
    }
};