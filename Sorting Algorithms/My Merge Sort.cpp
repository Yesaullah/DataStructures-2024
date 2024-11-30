#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int *temp = new int[high - low + 1];

    // traversing through the two sub arrays
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int index = 0; index < k; index++)
    {
        arr[low + index] = temp[index];
    }

    delete[] temp;
}

void mergesort(int arr[], int low, int high)
{
    // base case
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;

    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arrayTest[] = {4, 11, 1, 6, 12, 44, 1, 9};
    int size = sizeof(arrayTest) / sizeof(arrayTest[0]);
    cout << "Original array\n";
    printArray(arrayTest, size);
    mergesort(arrayTest, 0, size - 1);
    cout << "Sorted array\n";
    printArray(arrayTest, size);
    return 0;
}