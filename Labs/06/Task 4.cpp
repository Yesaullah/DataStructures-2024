#include <iostream>

using namespace std;

class Stack
{
    int top;
    int maxsize;
    int *arr;

public:
    Stack(int size)
    {
        top = -1;
        maxsize = size;
        arr = new int[maxsize];
    }

    bool is_full()
    {
        return top == maxsize - 1;
    }
    bool is_empty()
    {
        return top == -1;
    }

    void push(int data)
    {
        if (is_full())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++top] = data;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Queue
{
    Stack *s1;
    Stack *s2;

public:
    Queue(int size)
    {
        s1 = new Stack(size);
        s2 = new Stack(size);
    }
    ~Queue()
    {
        delete s1;
        delete s2;
    }

    void enqueue(int x)
    {
        s1->push(x);
        cout << x << " Enqueued!" << endl;
    }

    // in this function, the elements from stack1 will be popped and pushed onto stack2
    // then the top element in stack2 will be popped
    // then again all the elements will be transferred to stack1 in case more elements need to be pushed
    void dequeue()
    {
        while (!s1->is_empty())
        {
            s2->push(s1->pop());
        }
        // at this point s1 is empty and s2 is full
        int popped = s2->pop();
        cout << popped << " Dequeued!" << endl;

        // transfering the elements back to stack 1
        while (!s2->is_empty())
        {
            s1->push(s2->pop());
        }
    }

    void display()
    {
        while (!s1->is_empty())
        {
            s2->push(s1->pop());
        }
        cout << "Queue Elements: ";
        s2->display();

        // transfering the elements back to stack 1
        while (!s2->is_empty())
        {
            s1->push(s2->pop());
        }
    }
};

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();
}