#include <iostream>

using namespace std;

class Stack {
  int top;
  int size;
  char *arr;

 public:
  Stack() {
    top = -1;
    size = 10;
    arr = new char[size];
  }
  Stack(int n) {
    top = -1;
    size = n;
    arr = new char[size];
  }
  bool is_full() { return top == size - 1; }
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
// Function to return precedence of operators
int precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  if (op == '^') return 3;
  return 0;
}

string infix_to_postfix(string infix) {
  int length = infix.length();
  Stack S(length);
  string postfix = "";
  for (char &c : infix) {
    if (c == ' ') {
      continue;
    }
    // if the char is an operand it is eppended to the postfix string
    if (isalnum(c)) {
      postfix += c;
    }
    // if the char is opening bracker it is pushed on the stack
    else if (c == '(') {
      S.push(c);
    }
    // if the char is closing bracket, elements from the stack are popped until
    // opening bracket is encountere or the stack is empty
    else if (c == ')') {
      while (!S.is_empty() && S.peek() != '(') {
        postfix += S.peek();
        S.pop();
      }
      S.pop();  // Remove '(' from the stack
    }
    // if  the char is an operator
    else if (is_operator(c)) {
      // if the current operator has lower or equal precdence than the operator
      // at top in the stack
      while (!S.is_empty() && precedence(S.peek()) >= precedence(c)) {
        postfix += S.peek();
        S.pop();
      }
      S.push(c);  // Push the current operator to the stack
    }
  }
  while (!S.is_empty()) {
    postfix += S.peek();
    S.pop();
  }

  return postfix;
}

int main() {
  string infix;

  cout << "Enter an expression in infix notation: ";
  cin >> infix;

  cout << "Infix Expression: " << infix << endl;

  string postfix = infix_to_postfix(infix);
  cout << "Postfix Expression: " << postfix << endl;
}
