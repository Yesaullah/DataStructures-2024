#include <iostream>
#include <cctype> // for isalnum
using namespace std;


// Simple Stack class implementation
class Stack
{
    int top;
    int size;
    char *arr;

public:
    Stack()
    {
        top = -1;
        size = 10;
        arr = new char[size];
    }
    Stack(int n)
    {
        top = -1;
        size = n;
        arr = new char[size];
    }
    bool is_full()
    {
        return top == size - 1;
    }
    bool is_empty()
    {
        return top == -1;
    }
    void push(char value)
    {
        if (is_full())
        {
            cout << "Stack is full. Cannot push " << value << endl;
            return;
        }
        else
        {
            arr[++top] = value;
        }
    }
    char pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty. Cannot pop" << endl;
            return ' ';
        }
        else
        {
            return arr[top--];
        }
    }
    char peek()
    {
        if (is_empty())
        {
            cout << "Stack is empty. Cannot peek" << endl;
            return ' ';
        }
        else
        {
            return arr[top];
        }
    }
    ~Stack()
    {
        delete[] arr;
    }
};

// function to check if a character is an operator or not
bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// function to determine the precedence of an operator
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


string infix_to_prefix(string infix)
{
    // temperory stack to store the infix expression
    // this stack will be used to reverse the string
    Stack temp(infix.length());
    for (char &c : infix)
    {
        temp.push(c);
    }

    string reversed_infix = "";

    // popping characters from the stack until it gets empty
    while (!temp.is_empty())
    {
        char c = temp.pop();
        // if the character is an opening bracket it will be changed to a closing bracket
        if (c == '(')
        {
            c = ')';
        }
        // if the character is an closing bracket it will be changed to a opening bracket
        else if (c == ')')
        {
            c = '(';
        }
        reversed_infix += c;
    }

    Stack S(reversed_infix.length());
    string temp_prefix = "";

    for (char &c : reversed_infix)
    {
        if (c == ' ')
        {
            continue;
        }
        // if the char is an operand it is eppended to the postfix string
        if (isalnum(c))
        {
            temp_prefix += c;
        }
        // if the char is opening bracker it is pushed on the stack
        else if (c == '(')
        {
            S.push(c);
        }
        // if the char is closing bracket, elements from the stack are popped until opening bracket is encountere or the stack is empty
        else if (c == ')')
        {
            while (!S.is_empty() && S.peek() != '(')
            {
                temp_prefix += S.pop();
            }
            S.pop(); // Remove '(' from the stack
        }
        else if (is_operator(c))
        {
            // if the current operator has lower or equal precdence than the operator at top in the stack
            while (!S.is_empty() && precedence(S.peek()) >= precedence(c))
            {
                temp_prefix += S.pop();
            }
            S.push(c);
        }
    }
    // appending remaining operators in the stack to the string
    while (!S.is_empty())
    {
        temp_prefix += S.pop();
    }

    // reversing the resulting string again to get the actual prefix expression
    string prefix = "";
    for (char &c : temp_prefix)
    {
        temp.push(c);
    }
    while (!temp.is_empty())
    {
        prefix += temp.pop();
    }
    return prefix;
}

int main()
{
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";

    cout << "Infix Expression: " << infix << endl;

    string prefix = infix_to_prefix(infix);
    cout << "Prefix Expression: " << prefix << endl;
}
