#include <iostream>

using namespace std;

class Stack {
  int top;
  int capacity;
  char *arr;

 public:
  Stack() {
    top = -1;
    capacity = 10;
    arr = new char[capacity];
  }
  Stack(int n) {
    top = -1;
    capacity = n;
    arr = new char[capacity];
  }
  bool is_full() { return top == capacity - 1; }
  bool is_empty() { return top == -1; }
  void push(int value) {
    // if the stack is full
    if (is_full()) {
      cout << "Stack is full. Cannot push " << value << endl;
      return;
    } else {
      arr[++top] = value;
    }
  }
  void pop() {
    // if the stack is empty
    if (is_empty()) {
      cout << "Stack is empty. Cannot pop" << endl;
      return;
    } else {
      cout << "Popped: " << arr[top--] << endl;
    }
  }
  char peek() {
    if (is_empty()) {
      cout << "Stack is empty. Cannot peek" << endl;
      return ' ';
    } else {
      return arr[top];
    }
  }
  ~Stack() { delete[] arr; }
};

bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precdence(char c) {
  if (c == '+' || c == '-') {
    return 1;
  }
  if (c == '*' || c == '/') {
    return 2;
  }
  if (c == '^') {
    return 3;
  }
  return 0;
}

string infix_to_postfix(string infix) {
  int length = infix.length();
  Stack s(length);

  string postfix = "";
  for (char &c : infix) {
    // if the character is a blank space it is ignored
    if (c == ' ') {
      continue;
    }
    // if the character is an operand it is appended to the postfix expression 
    else if (isalnum(c)) {
      postfix += c;
    }
    // if the character is an opening bracket it is pushed onto the stack 
    else if (c == '(') {
      s.push(c);
    }
    // if the character is a closig bracket 
    // stack is popped until opening bracket is encountered
    // each popped element is appended in the postfix expression
    else if (c == ')') {
      while (!s.is_empty() && s.peek() != '(') {
        postfix += s.peek();
        s.pop();
      }
      s.pop();
    }
    // 
    else (is_operator(c)) {
      while (!s.is_empty() && precdence(s.peek()) >= precdence(c)) {
        postfix += s.peek();
        s.pop();
      }
      s.push(c);
    }
  }
  while (!s.is_empty()) {
    postfix += s.peek();
    s.pop();
  }

  return postfix;
}

int main() {
  string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";

  cout << "Infix Expression: " << infix << endl;

  string postfix = infix_to_postfix(infix);
  cout << "Postfix Expression: " << postfix << endl;
}