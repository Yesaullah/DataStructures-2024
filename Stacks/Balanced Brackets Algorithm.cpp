#include <iostream>
using namespace std;

class Stack{
    int size; // current elements in the stack
    int capacity; // max capacity of the stack
    char* str_arr;
public:
    Stack(){
        size = 0;
        capacity = 1;
        str_arr = new char[capacity];
    }
    Stack(int n){
        size = 0;
        capacity = n;
        str_arr = new char[capacity];
    }

    ~Stack(){
        delete[] str_arr;
    }

    void push(char ch){
        if(size == capacity){
            cout<<"Stack Overflow."<<endl;
        }
        else{
            str_arr[size++] = ch;
        }
    }

    char pop(){
        if(size == 0){
            cout<<"Stack Underflow."<<endl;
            return '\0';  
        }
        else{
            return str_arr[--size];
        }
    }

    bool is_empty(){
        return size == 0;
    }
};  

bool Balanced_Brackets(const string& str){
    Stack stack(str.length());

    for(char ch : str){
        if(ch == '('){
            stack.push(')');
        }   
        else if(ch == '{'){
            stack.push('}');
        }
        else if(ch == '['){
            stack.push(']');
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(stack.is_empty()){
                return false;
            }
            char temp = stack.pop();
            if(ch != temp){
                return false;
            }
        }
    }
    
    // After iterating through the string, the stack should be empty if the brackets are balanced
    return stack.is_empty();
}

int main(){
    string str = "(My name is Mohammad Yesaullah Sheikh})"; // imbalanced string
    string str2 = "({My name is Mohammad Yesaullah Sheikh})"; // balanced string

    if(Balanced_Brackets(str)){
        cout<<"'"<<str<<"' has balanced brackets."<<endl;
    }
    else{
        cout<<"'"<<str<<"' has unbalanced brackets."<<endl;
    }
    if(Balanced_Brackets(str2)){
        cout<<"'"<<str2<<"' has balanced brackets."<<endl;
    }
    else{
        cout<<"'"<<str2<<"' has unbalanced brackets."<<endl;
    }
}
