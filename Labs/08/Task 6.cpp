#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BST
{
    Node *root;
    Node *first;
    Node *second;
    Node *prev;

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        // traversing the left subtree
        inorderTraversal(node->left);

        if (prev != nullptr && prev->data > node->data)
        {
            if (first == nullptr)
            {
                // if it is the first violation then first stores the previous nodes data
                first = prev;
            }
            second = node;
        }
        prev = node;

        // traversing the right sub tree
        inorderTraversal(node->right);
    }

    void swapNode()
    {
        if (first != nullptr && second != nullptr)
        {
            swap(first->data, second->data);
        }
    }

public:
    BST() : root(nullptr), first(nullptr), second(nullptr), prev(nullptr) {}

    Node *getRoot()
    {
        return root;
    }

    void insert(int value)
    {
        root = insertRec(root, value);
    }

    Node *insertRec(Node *node, int value)
    {
        if (!node)
            return new Node(value);

        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else
        {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void recoverTree()
    {
        // Reset pointers
        first = second = prev = nullptr;

        // Perform inorder traversal to detect swapped nodes
        inorderTraversal(root);

        // Swap the two incorrect nodes
        swapNode();
    }

    void inorderPrint(Node *node)
    {
        if (!node)
            return;
        inorderPrint(node->left);
        cout << node->data << " ";
        inorderPrint(node->right);
    }

    void printInOrder()
    {
        inorderPrint(root);
        cout << endl;
    }
};
int main() {
    BST tree;

    // Construct BST with two swapped nodes
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(8);

    // Swapping nodes manually for testing
    Node* root = tree.getRoot();
    swap(root->left->data, root->right->data); // Swap 5 and 15

    cout << "Inorder traversal before recovery: ";
    tree.printInOrder();

    // Recover the tree
    tree.recoverTree();

    cout << "Inorder traversal after recovery: ";
    tree.printInOrder();

    return 0;
}