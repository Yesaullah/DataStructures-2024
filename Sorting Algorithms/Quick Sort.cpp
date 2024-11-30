#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int findPivotIndex(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high-1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low+1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotposition = findPivotIndex(arr, low, high);
        quicksort(arr, low, pivotposition - 1);
        quicksort(arr, pivotposition + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int index = 0; index < size; index++)
        cout << arr[index] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {3, 4, 7, 1, 66, 0, 2, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array : \n";
    printArray(arr, size);
    // quick sort
    quicksort(arr, 0, size - 1);
    cout << "After quick sort Array : \n";
    printArray(arr, size);

    return 0;
}