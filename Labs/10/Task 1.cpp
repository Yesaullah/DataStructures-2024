#include <iostream>
#include <vector>
using namespace std;

class member
{
public:
    int key;
    int index;

    member(int index, int key) : key(key), index(index) {}
};

class MaxHeap
{
    vector<member> array;

public:
    MaxHeap() {}

    void heapifyup()
    {
        int index = array.size() - 1;
        int parent = (index - 1) / 2;
        while (parent >= 0 && array[parent].key < array[index].key)
        {
            swap(array[parent], array[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void insert(member val)
    {
        array.push_back(val);
        heapifyup();
    }

    void heapifydown(int size, int parent)
    {
        int max = parent;
        while (true)
        {
            int left = parent * 2 + 1;
            int right = parent * 2 + 2;
            if (left < size && array[max].key < array[left].key)
                max = left;
            if (right < size && array[max].key < array[right].key)
                max = right;
            if (max == parent)
                break;
            swap(array[parent], array[max]);
            parent = max;
        }
    }

    member Root()
    {

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
            cout << "(" << array[i].index << ", " << array[i].key << ") ";
        }
        cout << endl;
    }
};

int main()
{
    int nums[] = {6, 7, 9, 2, 4, 0, 2, 5, 8};

    int size = 9;
    int k = 4;
    MaxHeap mh;
    cout << "K-size " << k << endl;
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    if (k > size)
        return 0;

    // Insert the first 'k' elements into the max heap
    for (int i = 0; i < k; i++)
    {
        member m(i, nums[i]);
        mh.insert(m);
    }
    cout << "\nSlide 1 max: " << mh.Root().key << endl;

    int check = 1;
    for (int i = k; i < size; i++)
    {
        member m(i, nums[i]);
        mh.insert(m);

        // Remove elements whose index is less than 'check' to maintain the window
        while (mh.Root().index < check)
        {
            mh.deleteRoot();
        }
        cout << "Slide " << check + 2 << " max: " << mh.Root().key << endl;
        check++;
    }

    return 0;
}