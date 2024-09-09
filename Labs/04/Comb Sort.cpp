#include <iostream>
using namespace std;

int getNextGap(int gap){
    gap = (gap*10)/13;
    if(gap<1){
        return 1;
    }
    return gap;
}

void CombSort(int arr[], int size){
    int gap = size;
    bool swapped = true;
    while(gap!=1 || swapped){
        gap = getNextGap(gap);
        swapped = false;
        
        // loop runs till size-gap as we compare with the element at the index i+gap
        for(int i = 0; i<size - gap; i++){
            if(arr[i]>arr[i+gap]){
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;

                swapped = true;
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

    CombSort(arr, size);

    cout<<"\nSorted Array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}