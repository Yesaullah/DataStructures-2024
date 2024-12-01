#include <iostream>
#include <vector>
using namespace std;
class MinHeap
{
    vector<int> array;

public:
    MinHeap() {}

    void heapifyup()
    {
        int index = array.size() - 1;
        int parent = (index - 1) / 2;
        while (parent >= 0 && array[parent] > array[index])
        {
            swap(array[parent], array[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void insert(int val)
    {
        array.push_back(val);
        heapifyup();
    }

    void heapifydown(int size, int parent)
    {
        int min = parent;
        while (true)
        {
            int left = parent * 2 + 1;
            int right = parent * 2 + 2;
            if (left < size && array[min] > array[left])
                min = left;
            if (right < size && array[min] > array[right])
                min = right;
            if (min == parent)
                break;
            swap(array[parent], array[min]);
            parent = min;
        }
    }

    int Root()
    {
        if (array.empty())
        {
            return -1;
        }
        return array[0];
    }

    void deleteRoot()
    {
        if (array.empty())
        {
            cout << "Empty\n";
            return;
        }
        array[0] = array[array.size() - 1];
        array.pop_back();
        heapifydown(array.size(), 0);
    }

    void display()
    {
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i];
        }
        cout << endl;
    }
};

void K_Largest(int array[], int size, int k)
{
    MinHeap mh;
    for (int i = 0; i < k; i++)
    {
        mh.insert(array[i]);
    }
    for (int i = k; i < size; i++)
    {
        if (array[i] > mh.Root())
        {
            mh.insert(array[i]);
            mh.deleteRoot();
        }
    }
    while (mh.Root() != -1)
    {
        cout << mh.Root() << " ";
        mh.deleteRoot();
    }
}
int main()
{
    int arr[] = {10, 1, 3, 5, 7, 19, 15};
    int k = 3;
    int size = 7;
    K_Largest(arr, size, k);
}