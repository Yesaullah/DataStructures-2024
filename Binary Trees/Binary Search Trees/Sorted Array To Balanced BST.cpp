#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int key) : data(key), left(nullptr), right(nullptr) {}
};

Node *sortedArrayToBST(vector<int> &arr, int low, int high)
{
    if (low > high)
    {
        return nullptr;
    }
    int mid = low + (high - low) / 2;

    // root node of the new BST
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, low, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, high);

    return root;
}

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    Node *root = sortedArrayToBST(arr, 0, n - 1);
    preOrder(root);
}