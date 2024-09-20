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

void BinarySearch(int arr[], int size, int target){
    int max = size -1;
    int min = 0;

    bool swapped = false;
    while(!swapped){
        if(min>max){
            cout<<"Element not found in the array."<<endl;
            swapped=true;
            break;
        }
        int mid = (min+max)/2;
        if(target == arr[mid]){
            cout<<"Element found at index "<<mid<<endl;
            swapped = true;
            break;
        }
        else if(target > arr[mid]){
            min = mid+1;
        }
        else{
            max = mid - 1;
        }
    }
}

int main(){
    int arr[] = {1, 2, 6, 8, 3, 23};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int target = 6;

    BubbleSort(arr, size);

    BinarySearch(arr, size, target);
}