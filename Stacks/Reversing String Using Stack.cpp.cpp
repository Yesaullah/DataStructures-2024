#include<iostream>
#include <string>
using namespace std;

class Stack{
    int size;
    int capacity;
    char* str_arr;
    public:
    Stack(int c){
        capacity = size;
        str_arr = new char[capacity];
        size = 0;
    }
    ~Stack(){
        delete[] str_arr;
    }

    void push(char ch){
        if(size == capacity){
            cout<<"Stack Overflow."<<endl;
            return;
        }
        str_arr[size++] = ch;
    }

    char pop(){
        if(size == 0){
            cout<<"Stack underflow."<<endl;
            return '\0';
        }
        return str_arr[--size];
    }

    bool is_empty(){
        return size == 0;
    }
};


string reverse_string(const string& str){
    int length = str.length();

    Stack stack(length);

    for(char ch : str){
        stack.push(ch);    
    }
    string reversed = "";
    while(!stack.is_empty()){
        reversed += stack.pop();
    }

    return reversed;
}

int main(){
    string str = "Apple";

    string string_reversed = reverse_string(str);

    cout<<"Original String: "<<str<<endl;
    cout<<"Reversed String: "<<string_reversed<<endl;
}