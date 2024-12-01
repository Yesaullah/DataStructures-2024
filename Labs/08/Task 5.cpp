#include <iostream>
#include <queue>
#include <deque>

using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
    friend class BinarySearchTree;
};

class BinarySearchTree
{
    Node *root;

public:
    BinarySearchTree() : root(nullptr) {}
    
    Node *ArrayToBST(int arr[], int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;

        Node *node = new Node(arr[mid]); // root of the new tree

        node->left = ArrayToBST(arr, start, mid - 1);
        node->right = ArrayToBST(arr, mid + 1, end);

        return node;
    }

    void inOrderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;

    BinarySearchTree tree;
    Node *root = tree.ArrayToBST(arr, 0, n);

    cout << "In-order Traversal of the BST: ";
    tree.inOrderTraversal(root);

    return 0;
}