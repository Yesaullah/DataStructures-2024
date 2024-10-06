#include <iostream>

using namespace std;

#define capacity 10

class Ticket_Queue{
    int front;
    int rear;
    string *queue;
    public:
    Ticket_Queue(){
        front = 0;
        rear = -1;
        queue = new string[capacity];
    }

    bool is_full(){
        return rear == capacity - 1;
    }
    bool is_empty(){
        return front>rear || front == -1;
    }

    void buy_ticket(string name){
        if(is_full()){
            cout<<"Queue is full at the moment!"<<endl;
            return;
        }
        queue[++rear] = name;
        cout<<name<<" Enqueued!"<<endl;
    }

    void move_to_next(){
        if(is_empty()){
            cout<<"The queue is now empty!"<<endl;
            return;
        }
        cout<<queue[front]<<" is done with the process now!"<<endl;
        front++;
    }

    string peek(){
        if(is_empty()){
            cout<<"Queue is empty!"<<endl;
            return " ";
        }
        return queue[front];
    }

    void display(){
        if(is_empty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<"People standing in the queue: ";
        for(int i = front; i<=rear; i++){
            cout<<queue[i]<<' ';
        }
        cout<<endl;
    }
};  


int main(){
    Ticket_Queue q;

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

    q.display();

    cout<<endl;

    // removing 5 people from the queue
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    cout<<endl;
    
    q.display();

    cout<<endl;

    // adding 5 more people to the queue

    // however these people wont be enqueued as the rear has already reached the end of the array, when we removed the elements from the front it didnt change the rear pointer
    q.buy_ticket("Amarha");
    q.buy_ticket("Leeya");
    q.buy_ticket("Rida");
    q.buy_ticket("Ehtisham");
    q.buy_ticket("Hassan");
    cout<<endl;

    q.display();
}
