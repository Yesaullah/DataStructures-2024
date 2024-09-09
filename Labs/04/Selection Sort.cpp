#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        if(min_index!=i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main(){
    int arr[] = {4, 6, 2, 3, 8, 11};
    int size = sizeof(arr)/arr[0];

    cout<<"Unsorted Array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    SelectionSort(arr, size);

    cout<<"\nSorted Array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}