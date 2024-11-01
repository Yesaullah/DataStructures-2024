#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}

    friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
    Node *root;
    BinarySearchTree() : root(nullptr) {}

    Node *insert(Node *root, int value)
    {
        if (root == nullptr)
        {
            return new Node(value);
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        return root;
    }

    bool search(Node *root, int value)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == value)
        {
            return true;
        }
        else if (value < root->data)
        {
            return search(root->left, value);
        }
        else
        {
            return search(root->right, value);
        }
    }

    Node *findMin(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    Node *findMax(Node *root)
    {
        while (root && root->right)
        {
            root = root->right;
        }
        return root;
    }

    Node *deleteNode(Node *root, int value)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (value < root->data)
        {
            root->left = deleteNode(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = deleteNode(root->right, value);
        }
        // if the node with target value is found
        else
        {
            // Node with only one or no child
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            // get the inorder successor (smallest in the right subtree)
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    int height(Node *root)
    {
        // base case:
        // if the tree is empty
        // or
        // if the leaf node is reached
        if (root == nullptr)
        {
            return -1;
        }
        int left_height = height(root->left);   // height of the left sub-tree
        int right_height = height(root->right); // height of the right sub-tree

        return max(left_height, right_height) + 1; // returns the larger height + 1 for the current node
    }

    void printGivenLevel(Node *root, int level)
    {
        if (!root)
        {
            return;
        }
        if (level == 0)
        {
            cout << root->data << endl;
        }
        else
        {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }

    void levelOrder(Node *root)
    {
        int h = height(root);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(root, i);
        }
    }

    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node *root)
    {
        if (root)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void reverseInorder(Node *root, int &count, int &result)
    {
        if (root == nullptr || count >= 2)
        {
            return;
        }

        reverseInorder(root->right, count, result);

        count++;

        if (count == 2)
        {
            result = root->data;
            return;
        }

        reverseInorder(root->left, count, result);
    }
    int findSecondLargest(Node *root)
    {
        int count = 0;
        int result = -1;

        reverseInorder(root, count, result);

        return result;
    }

    // highest value in the tree that is less than or equal to the given value.
    int findfloor(Node *root, int x)
    {
        int floorvalue = INT_MIN;
        while (root)
        {
            if (root->data == x)
            {
                return root->data;
            }
            if (root->data < x)
            {
                floorvalue = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floorvalue;
    }

    // lowest value in the tree that is greater than or equal to the given value.
    int findceil(Node *root, int x)
    {
        int ceilvalue = INT_MAX;
        while (root)
        {
            if (root->data == x)
            {
                return root->data;
            }
            if (root->data > x)
            {
                ceilvalue = root->data;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return ceilvalue;
    }
};

int main()
{
    BinarySearchTree tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    int value = 40;
    if (tree.search(tree.root, value))
    {
        cout << value << " found in the tree.\n";
    }
    else
    {
        cout << value << " not found in the tree.\n";
    }

    cout << "Minimum value: " << tree.findMin(tree.root)->data << endl;
    cout << "Maximum value: " << tree.findMax(tree.root)->data << endl;

    int secondLArgest = tree.findSecondLargest(tree.root);
    cout << "The second largest value in the tree is: " << secondLArgest << endl;

    cout << "Deleting 20\n";
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "Inorder traversal after deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Deleting 30\n";
    tree.root = tree.deleteNode(tree.root, 30);
    cout << "Inorder traversal after deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Deleting 50\n";
    tree.root = tree.deleteNode(tree.root, 50);
    cout << "Inorder traversal after deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}