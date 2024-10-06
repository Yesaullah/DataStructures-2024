#include <iostream>
using namespace std;

class Queue{
    int front; // position where elements are removed from
    int rear; // position where are added to
    int capacity;
    char* queue;
    public:
    // default constructor
    Queue(){
        front = -1;
        rear = -1;
        capacity = 5;
        queue = new char[capacity];
    }
    // parameterized constructor
    Queue(int c){
        front = -1;
        rear = -1;
        capacity = c;
        queue = new char[capacity];
    }
    // destrcutor
    ~Queue(){
        delete[] queue;
    }

    // mehtod to add element to the queue
    void enqueue(char ch){
        if(rear == capacity - 1){
            cout<<"Queue Overflow!"<<endl;
            return;
        }
        // if it is the first time enqueue() is being called front will be set to 0
        if(front == -1){
            front = 0;
        }
        queue[++rear] = ch;
        cout<<ch<<" Enqueued!"<<endl;
    }

    // method to remove an element from the queue
    void dequeue(){
        if(front == -1){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        if(front > rear){
            cout<<"All present elements were dequed!"<<endl;
            front = rear = -1;
            return;
        }

        // if some element is present in the queue then it will be dequeued
        cout<<queue[front]<<" Dequeued!"<<endl;
        front++;
    }

    // method to get the element at the front of the queue
    char peek(){
        if(front == -1){
            cout<<"Queue is empty!"<<endl;
            return ' ';
        }
        return queue[front];
    }

    // method to display the queue
    void display(){
        if(front == -1){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<"Queue elements: ";
        for(int i = front; i<=rear; i++){
            cout<<queue[i]<<' ';
        }
        cout<<endl;
    }
};

int main(){
    Queue q(5);

    q.dequeue();

    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');
    q.enqueue('e');
    
    q.display();

    q.enqueue(6);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.display();
}