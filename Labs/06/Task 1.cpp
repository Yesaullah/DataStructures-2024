#include <iostream>
using namespace std;

class Stack {
  int top;
  int capacity;
  int* arr;

 public:
  Stack() {
    top = -1;
    capacity = 10;
    arr = new int[capacity];
  }
  Stack(int c) {
    top = -1;
    capacity = c;
    arr = new int[capacity];
  }

  // check if the stack is full
  bool is_full() { return top == capacity - 1; }

  // check if the stack is empty
  bool is_empty() { return top == -1; }

  // get the current size of the stack
  int get_size() { return top + 1; }

  void push(int value) {
    // if the stack is full
    if (is_full()) {
      cout << "Stack Overflow!" << endl;
      return;
    }
    arr[++top] = value;
  }

  int pop() {
    if (is_empty()) {
      cout << "Stack Underflow!" << endl;
      return -1;
    }
    return arr[top--];
  }

  void print_stack(){
    if(is_empty()){
      cout<<"Stack is empty."<<endl;
      return;
    }
    for(int i = 0; i<=top; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};

void even_odd_seperator(Stack& S, Stack& even, Stack& odd, int size){
  int element;
  for (int i = 0; i<size; i++){
    element = S.pop();
    if(element%2 == 0){
      even.push(element);
    }
    else{
      odd.push(element);
    }
  }
}

int main(){
  Stack S(10);

  S.push(1);
  S.push(2);
  S.push(3);
  S.push(4);
  S.push(5);
  S.push(6);
  S.push(7);
  S.push(8);
  S.push(9);
  S.push(10);

  cout << "Original Stack: ";
  S.print_stack();

  int size = S.get_size();

  Stack even(size);
  Stack odd(size);

  even_odd_seperator(S, even, odd, size);

  cout<<"Even Stack: ";
  even.print_stack();

  cout<<"Odd Stack: ";
  odd.print_stack();

  cout << "Original Stack: ";
  S.print_stack();
}