#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    public:
    Node(): data(0), next(nullptr){}
    Node(int value): data(value), next(nullptr){}

    friend class Stack;
};

class Stack{
    Node* topnode;
    int count;
    public:
    Stack(){
        topnode = nullptr;
        count = 0;
    }

    // push an element onto the stack
    void push(int value){
        Node* newnode = new Node();
        newnode->data = value;
        newnode->next = topnode; // next is made to point towards the last node
        topnode = newnode;
        count++;
    }

    // check if the stack is empty
    bool is_empty(){
        return topnode==nullptr;
    }

    // pop an item from the stack
    void pop(){
        if(is_empty()){
            cout<<"Stack Underflow! Cannot pop."<<endl;
            return;
        }
        Node* temp = topnode;
        topnode = topnode->next;
        cout<<temp->data<<" popped from stack."<<endl;
        delete temp;
        count--;
    }

    // get the top element of the stack
    int peek(){
        if(is_empty()){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        return topnode->data;
    }

    // get the size of the stack
    int size(){
        return count;
    }

    void display(){
        if(is_empty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        Node* temp =topnode;
        cout<<"Stack elements: ";
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // destructor to clean up the memeory
    ~Stack(){
        while(!is_empty()){
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    
    cout << "Top element is: " << stack.peek() << endl;
    
    stack.pop();
    stack.display();

    cout << "Stack size is: " << stack.size() << endl;

    return 0;
}