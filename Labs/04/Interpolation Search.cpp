#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int InterpolationSearch(int arr[], int size, int target)
{
    int min = 0;
    int max = size - 1;

    while (min <= max && target >= arr[min] && target <= arr[max])
    {
        if (min == max)
        {
            if (arr[min] == target)
            {
                return min;
            }
            return -1;
        }

        // Avoid division by zero
        if (arr[max] == arr[min])
        {
            if (arr[min] == target)
            {
                return min;
            }
            return -1;
        }

        int pos = min + ((target - arr[min]) * (max - min)) / (arr[max] - arr[min]);

        if (arr[pos] == target)
        {
            return pos;
        }
        else if (arr[pos] > target)
        {
            max = pos - 1;
        }
        else
        {
            min = pos + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 6, 8, 3, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    BubbleSort(arr, size);
    int result = InterpolationSearch(arr, size, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}
