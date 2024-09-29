// #include <iostream>
// using namespace std;

// int recursive_binary_search(int arr[], int target, int low, int high)
// {
//     if (high >= low)
//     {
//         int mid = low + ((high - low) / 2);
//         if (arr[mid] == target)
//         {
//             return mid;
//         }
//         else if (arr[mid] > target)
//         {
//             return recursive_binary_search(arr, target, low, mid - 1);
//         }
//         else if (arr[mid] < target)
//         {
//             return recursive_binary_search(arr, target, mid + 1, high);
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int arr[] = {4, 3, 6, 8, 2, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Your Array: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << ", ";
//     }
//     cout << endl;

//     int target;
//     cout << "Enter the element you want to search in the array: ";
//     cin >> target;

//     int index = recursive_binary_search(arr, target, 0, n - 1);

//     if (index == -1)
//     {
//         cout << "Element not found.";
//     }
//     else
//     {
//         cout << "Element found at index " << index;
//     }
// }

#include <iostream>
using namespace std;

int recursive_binarysearch(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return recursive_binarysearch(arr, left, mid - 1, target);
    }
    else
    {
        return recursive_binarysearch(arr, mid + 1, right, target);
    }
}

int main()
{
    int arr[] = {3, 5, 7, 9, 13};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter a number to search in the array: ";
    cin >> target;

    int result = recursive_binarysearch(arr, 0, size - 1, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}