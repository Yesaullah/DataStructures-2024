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
        while (index > 0 && array[parent] > array[index])
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
        return array.empty() ? -1 : array[0];
    }

    void deleteRoot()
    {
        if (array.empty())
        {
            cout << "Empty\n";
            return;
        }
        array[0] = array.back();
        array.pop_back();
        heapifydown(array.size(), 0);
    }

    void display()
    {
        for (int val : array)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr) {}
};

class SingleLinkedList
{
    Node *root;

public:
    SingleLinkedList() : root(nullptr) {}
    Node *getRoot()
    {
        if (root)
            return root;
        return NULL;
    }
    void insert(int d)
    {
        Node *n = new Node(d);
        if (!root)
        {
            root = n;
            return;
        }
        Node *temp = root;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void display()
    {
        if (!root)
        {
            cout << "Empty\n";
            return;
        }
        Node *temp = root;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void k_sort(vector<Node *> lists)
{
    SingleLinkedList merged;
    MinHeap mh;
    int k = lists.size();

    // Insert first elements of all lists into the heap
    for (int i = 0; i < k; i++)
    {
        if (lists[i])
            mh.insert(lists[i]->data);
    }

    while (true)
    {
        // Check if all lists are empty
        bool check = true;
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != nullptr)
            {
                check = false;
                break;
            }
        }
        if (check)
            break;

        // Process each list
        for (int i = 0; i < k; i++)
        {
            if (!lists[i])
                continue;

            if (lists[i]->data == mh.Root())
            {
                merged.insert(mh.Root());
                mh.deleteRoot();
                lists[i] = lists[i]->next;

                if (lists[i])
                    mh.insert(lists[i]->data);
            }
        }
    }

    cout << "Displaying Merged:\n";
    merged.display();
}

int main()
{
    // Create multiple linked lists with at least 4 nodes each
    SingleLinkedList list1, list2, list3;

    // Adding nodes to list1
    list1.insert(1);
    list1.insert(4);
    list1.insert(7);
    list1.insert(10);

    // Adding nodes to list2
    list2.insert(3);
    list2.insert(5);
    list2.insert(8);
    list2.insert(11);

    // Adding nodes to list3
    list3.insert(2);
    list3.insert(6);
    list3.insert(9);
    list3.insert(12);

    // Vector of linked list roots
    vector<Node *> lists = {list1.getRoot(), list2.getRoot(), list3.getRoot()};

    // Perform k-way merge
    k_sort(lists);

    return 0;
}
