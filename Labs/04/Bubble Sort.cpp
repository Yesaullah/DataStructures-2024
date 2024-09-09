#include <iostream>

using namespace std;

void BubbleSort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {4, 6, 2, 3, 8, 11};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted Array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    BubbleSort(arr, size);

    cout<<"\nSorted Array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}