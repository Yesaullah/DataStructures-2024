#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int* max_arr;
    int top;
    int max_top;
    int capacity;
    public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        max_arr = new int[capacity];
        top = -1;
        max_top = -1;
    }
    bool is_max_empty(){
        return max_top == -1;
    }
    bool is_empty(){
        return top == -1;
    }
    bool is_max_full(){
        return max_top == capacity-1;
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
        // if the max_arr is empty or if the top element in it is greater than x
        if(max_top == -1 || x > max_arr[max_top]){
            max_arr[++max_top] = x;
        }
    }
    void pop(){
        if(is_empty()){
            cout<<"Stack Underflow."<<endl;
            return;
        }
        if(max_arr[max_top] == arr[top]){
            --max_top;
        }
        --top;
    }
    int peek_max(){
        if(is_max_empty()){
            cout<<"Stack Underflow."<<endl;
            return -1;
        }
        return max_arr[max_top];
    }

    ~Stack(){
        delete[] arr;
        delete[] max_arr;
    }
};

int main(){
    int arr[] = {4, 6, 34, 65, 23, 3, 78, 65, 84, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    Stack stack(size);

    for(int i =0; i<size ; i++){
        stack.push(arr[i]);
    }

    int max_element = stack.peek_max();
    cout<<"The maximum element in the array is: "<<max_element<<endl;
}
