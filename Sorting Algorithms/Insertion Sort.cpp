#include <iostream>

using namespace std;

void InsertionSort(int arr[], int size)
{
    // starting from i = 1, making the first element the sorted array
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // the code inside te following loop only executes when the element from the unsorted part is less then the element in the sorted part
        while (j >= 0 && arr[j] > key)
        {
            // element is shifted one place to the right
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {4, 6, 2, 3, 8, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    InsertionSort(arr, size);

    cout << "\nSorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}