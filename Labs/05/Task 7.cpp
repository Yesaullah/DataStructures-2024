#include <iostream>

using namespace std;

class Stack{
    int top; // keeps track of the index of the last element entered in the stack
    int maxsize;
    int* arr; // dynamic array for the stack
    public:
    Stack(int size){
        maxsize = size;
        top = -1;
        arr = new int[maxsize];
    }

    // check if the stack is full
    bool is_full(){
        return top == maxsize - 1;
    }

    // check if the stack is empty
    bool is_empty(){
        return top == -1;
    }   

    // get the current size of the stack
    int get_size(){
        return top + 1;
    }

    // push an element to the stack
    void push(int value){
        // if the stack is full
        if(is_full()){
            cout<<"Stack Overflow! Cannot push "<<value<<endl;
            return;
        }
        arr[++top] = value;
        cout<<value<<" pushed onto stack."<<endl;
    }

    // pop an element from the stack
    void pop(){
        // if the stack is empty
        if(is_empty()){
            cout<<"Stack Underflow! Cannot pop."<<endl;
            return;
        }
        cout<<arr[top--]<<" popped from the stack."<<endl;
    }

    // get the top element from the stack
    int peek(){
        // if the stack is empty
        if(is_empty()){
            cout<<"Stack is empty!"<<endl;
            return -1; // return a default invalid value when the stack is empty
        }
        return arr[top];
    }

    // Display all elements in the stack
    void display(){
        // if the stack is empty
        if(is_empty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        cout<<"Stack Elements: ";
        for(int i = 0; i<=top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // destructor to free the memory
    ~Stack(){
        delete[] arr;
    }
};

int main(){
    // stack with maxsize 5
    Stack stack(5);

    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(0);
    
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;
    
    stack.pop();
    stack.display();

    cout << "Stack size is: " << stack.get_size() << endl;

    return 0;
}