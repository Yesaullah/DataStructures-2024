#include <iostream>
using namespace std;

void LinearSearch(int arr[], int size, int target){
    for(int i = 0; i<size; i++){
        if(arr[i] == target){
            cout<<"Element found at index: "<<i<<endl;
            return;
        }
    }
}

int main(){
    int arr[] = {1, 2, 6, 8, 3, 23};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int target = 6;

    LinearSearch(arr, size, target);
}