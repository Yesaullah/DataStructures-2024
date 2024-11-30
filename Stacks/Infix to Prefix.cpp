#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to perform infix to prefix conversion
string infixToPrefix(string infix) {
    stack<char> operators;
    stack<string> operands;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If character is an operand, push it to the operand stack
        if (isalnum(ch)) {
            operands.push(string(1, ch));
        }
        // If character is '(', push it to the operator stack
        else if (ch == '(') {
            operators.push(ch);
        }
        // If character is ')', pop from operator and operand stacks until '(' is found
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();

                string temp = op + op1 + op2;
                operands.push(temp);
            }
            operators.pop(); // Pop '('
        }
        // If character is an operator
        else if (isOperator(ch)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                char op = operators.top();
                operators.pop();

                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();

                string temp = op + op1 + op2;
                operands.push(temp);
            }
            operators.push(ch);
        }
    }

    // Pop remaining operators
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();

        string temp = op + op1 + op2;
        operands.push(temp);
    }

    // Final prefix expression
    return operands.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Reverse the infix expression to process for prefix
    reverse(infix.begin(), infix.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string prefix = infixToPrefix(infix);

    // Reverse the final result
    reverse(prefix.begin(), prefix.end());

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
