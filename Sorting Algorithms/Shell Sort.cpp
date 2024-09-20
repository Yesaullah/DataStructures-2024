#include <iostream>
using namespace std;

void ShellSort(int arr[], int size){
    for(int gap = size/2; gap>0; gap /= 2){
        for(int i = gap; i<size; i++){
            for(int j = i-gap; j>=0; j-=gap){
                if(arr[j+gap]>arr[j]){
                    break;
                }
                else{
                    int temp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j+gap] = temp;
                }
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

    ShellSort(arr, size);

    cout<<"\nSorted Array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}