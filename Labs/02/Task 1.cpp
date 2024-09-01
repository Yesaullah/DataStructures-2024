#include <iostream>
using namespace std;

int main()
{
    int rows = 5;

    // Array of pointers
    // Here each pointer points to a f=different row
    int **Array = new int *[rows];

    // Allocating memory for each row
    int size[5] = {2, 3, 6, 1, 4};
    for (int i = 0; i < rows; ++i)
    {
        Array[i] = new int[size[i]];
    }

    int elements[5];
    // Copying data to a new array

    // Allocating new memory for each row
    for (int i = 0; i < rows; ++i)
    {
        cout << "Enter number of elements for row " << i + 1 << ": ";
        cin >> elements[i];
        int *temp = new int[elements[i]];
        for (int j = 0; j < size[i]; ++j)
        {
            temp[j] = Array[i][j];
        }
        delete[] Array[i];
        Array[i] = temp;
    }

    // Taking inputs for the resized rows
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < elements[i]; ++j)
        {
            cout << "Enter the value for the index [" << i << "][" << j << "]: ";
            cin >> Array[i][j];
        }
    }

    // Printing the jagged array
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < elements[i]; ++j)
        {
            cout << "Value at index [" << i << "][" << j << "]: ";
            cout << Array[i][j] << endl;
        }
    }
}
