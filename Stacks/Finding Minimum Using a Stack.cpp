#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int* min_arr;
    int top;
    int min_top;
    int capacity;
    public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        min_arr = new int[capacity];
        top = -1;
        min_top = -1;
    }
    bool is_min_empty(){
        return min_top == -1;
    }
    bool is_empty(){
        return top == -1;
    }
    bool is_min_full(){
        return min_top == capacity-1;
    }
    bool is_full(){
        return top == capacity-1;
    }
    void push(int x){
        if(is_full()){
            cout<<"Stack Overflow."<<endl;
            return;
        }
        arr[++top] = x;
        // if the min_arr is empty or if the top element in it is greater than x
        if(min_top == -1 || x < min_arr[min_top]){
            min_arr[++min_top] = x;
        }
    }
    void pop(){
        if(is_empty()){
            cout<<"Stack Underflow."<<endl;
            return;
        }
        if(min_arr[min_top] == arr[top]){
            --min_top;
        }
        --top;
    }
    int peek_min(){
        if(is_min_empty()){
            cout<<"Stack Underflow."<<endl;
            return -1;
        }
        return min_arr[min_top];
    }

    ~Stack(){
        delete[] arr;
        delete[] min_arr;
    }
};

int main(){
    int arr[] = {4, 6, 34, 65, 23, 3, 78, 65, 84, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    Stack stack(size);
    for(int i =0; i<size ; i++){
        stack.push(arr[i]);
    }

    int min_element = stack.peek_min();
    cout<<"The minimum element in the array is: "<<min_element<<endl;
}