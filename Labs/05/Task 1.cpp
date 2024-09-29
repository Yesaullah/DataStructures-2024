#include <iostream>
using namespace std;

// using bubble sort as the sorting algorithm
void recursive_bubbleSort(int arr[], int size)
{
    if (size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    recursive_bubbleSort(arr, size - 1);
}

int main()
{
    int arr[] = {3, 2, 6, 1, 18, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;

    recursive_bubbleSort(arr, size);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
}