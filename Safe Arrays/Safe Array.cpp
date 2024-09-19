#include <iostream>
using namespace std;

class Safe_Array{
    int size;
    int capacity;
    int *arr = NULL;
    public:
    Safe_Array(){
        size = 0;
        capacity = 5;
        arr = new int[capacity];
    }
    Safe_Array(int n){
        size = 0;
        capacity = n;
        arr = new int[capacity];
    }

    // WHEN SIZE AND CAPACITY BECOME EQUAL, CAPACITY IS DOUBLED
    void grow_array(){
        capacity = capacity*2;

        int* temp = new int[capacity];
        for(int i = 0; i<size; i++){
            temp[i] = arr[i];
        }
        delete[] arr;

        arr = temp;
    }

    // REMOVES UNUSED INDEXES
    void shrink_array(){
        capacity = size;
        int *temp = new int[capacity];
        for(int i = 0; i<size; i++){
            temp[i] = arr[i];
        }
        delete[] arr;

        arr = temp;
    }

    // INSERTION AT THE END
    void push_back(int value){
        // if the array is full
        if(size==capacity){
            grow_array();
        }
        arr[size] = value;
        size++;
        cout<<"Element pushed at the end."<<endl;
    }

    // DELETION FROM THE END
    void pop_back(){
        if(size == 0){
            cout<<"Array is empty."<<endl;
        }
        else{
            arr[size-1] = 0;
            size--;

            if(size==capacity/2){
                shrink_array();
            }
            cout<<"Element popped from the end."<<endl;
        }
    }

    // Displays the array
    void display(){
        if(size == 0){
            cout<<"The array is empty."<<endl;
            return;
        }
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    // DESTRUCTOR
    ~Safe_Array(){
        delete[] arr;
    }
};

int main(){
    Safe_Array array;

    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    
    array.display();

    array.pop_back();
    array.pop_back();

    array.display();
}