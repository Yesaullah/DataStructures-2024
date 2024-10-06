#include <iostream>

using namespace std;

class Queue{
    int front; // elements will be dequeued from here
    int rear; // elements will be added here
    int count; // keeps account of the elements present in the queue
    int capacity; // stores the max capacity of the queue
    string* queue;
    public:
    Queue(){
        front = 0;
        rear = -1;
        count = 0;
        capacity = 10;
        queue = new string[capacity];
    }

    ~Queue(){
        delete[] queue;
    }

    bool is_full()
    {
        return count == capacity;
    }
    bool is_empty()
    {
        return count == 0;
    }

    void buy_ticket(string name){
        if(is_full()){
            cout<<"Queue is full!"<<endl;
            return;
        }
        rear = (rear + 1)%capacity;
        queue[rear] = name;
        count++;
        cout<<name<<" Enqueued!"<<endl;
    }

    void move_to_next(){
        if(is_empty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<queue[front]<<" is done with the process now!"<<endl;
        front = (front+1)%capacity;
        count--;
    }

    void display_queue(){
        if(is_empty()){
            cout<<"Queue is empty!"<<endl;
        }
        for(int i =0; i<count; i++){
            cout<<queue[(front + i)%capacity]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q;

    q.display_queue();

    // adding 10 people to the queue
    q.buy_ticket("Yesaullah");
    q.buy_ticket("Hasnain");
    q.buy_ticket("Shadab");
    q.buy_ticket("Sabeeh");
    q.buy_ticket("Muhammad");
    q.buy_ticket("Huzaifa");
    q.buy_ticket("Haris");
    q.buy_ticket("Muneeb");
    q.buy_ticket("Hamza");
    q.buy_ticket("Murtaza");
    cout<<endl;

    q.display_queue();

    cout<<endl;

    // removing 5 people from the queue
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    cout<<endl;
    
    q.display_queue();

    cout<<endl;

    // adding 5 more people to the queue

    // however these people wont be enqueued as the rear has already reached the end of the array, when we removed the elements from the front it didnt change the rear pointer
    q.buy_ticket("Amarha");
    q.buy_ticket("Leeya");
    q.buy_ticket("Rida");
    q.buy_ticket("Ehtisham");
    q.buy_ticket("Hassan");
    cout<<endl;

    q.display_queue();
}
