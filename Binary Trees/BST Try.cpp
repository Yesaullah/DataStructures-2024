#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node() : data(-1), left(nullptr), right(nullptr) {}
    Node(int d) : data(d), left(nullptr), right(nullptr) {}

    friend class BST;
};

class BST
{
public:
    // TRAVERSAL METHODS
    void preorder_traversal(Node *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    void inorder_traversal(Node *root)
    {
        if (!root)
        {
            return;
        }
        preorder_traversal(root->left);
        cout << root->data << " ";
        preorder_traversal(root->right);
    }
    void postorder_traversal(Node *root)
    {
        if (!root)
        {
            return;
        }
        preorder_traversal(root->left);
        preorder_traversal(root->right);
        cout << root->data << " ";
    }

    // ADDING A NEW NODE (RECURSIVE METHOD)
    void insertNode(Node *&root, int value)
    {
        if (!root)
        {
            root = new Node(value);
        }
        if (value == root->data)
        {
            return;
        }
        else if (value > root->data)
        {
            insertNode(root->right, value);
        }
        else
        {
            insertNode(root->left, value);
        }
    }

    // ADDING A NEW NODE USING A LOOP
    void insertNewNode(Node *&root, int key)
    {
        Node *newnode = new Node(key);
        if (!root)
        {
            root = newnode;
            return;
        }
        if (root->data == key)
        {
            return;
        }
        Node *temp = root;
        while (true)
        {
            // left sub tree
            if (key < temp->data)
            {
                if (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = newnode;
                    break;
                }
            }

            // right sub tree
            else
            {
                if (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = newnode;
                    break;
                }
            }
        }
    }

    // SEARCHING FUNCTION
    Node *searchNode(Node *root, int key)
    {
        if (!root)
        {
            return root;
        }
        Node *temp = root;
        while (!temp)
        {
            if (key == temp->data)
            {
                return temp;
            }
            else if (key > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        return temp;
    }

    // RECURSIVE METHD FOR SEARCHING
    bool searchRecursion(Node *node, int key)
    {
        if (!node)
        {
            return false;
        }
        if (node->data == key)
        {
            return true;
        }
        if (key < node->data)
        {
            return searchRecursion(node->left, key);
        }
        return searchRecursion(node->right, key);
    }

    // FUNCTION TO DETERMNE THE HEIGHT OF THE TREE
    int height(Node *root)
    {
        if (!root)
        {
            return -1;
        }
        else
        {
            int left_height = height(root->left);
            int right_height = height(root->right);

            return (left_height > right_height) ? left_height + 1 : right_height + 1;
        }
    }

    void printGivenLevel(Node *root, int level)
    {
        if (!root)
        {
            return;
        }
        else if (level == 0)
        {
            cout << root->data << " ";
        }
        else
        {
            printGivenLevel(root->left, level--);
            printGivenLevel(root->right, level--);
        }
    }

    void printLevelOrderBFS(Node *root)
    {
        int h = height(root);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(root, i);
        }
    }

    Node *findMinValue(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    // DELETING A NODE
    Node *deleteNode(Node *root, int value)
    {
        if (!root)
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
        else
        {
            if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = findMinValue(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        return root;
    }
};

#include <iostream>
using namespace std;

int main()
{
    BST tree;             // create a binary search tree object
    Node *root = nullptr; // initialize root as nullptr

    // Inserting nodes using recursive method
    tree.insertNode(root, 50);
    tree.insertNode(root, 30);
    tree.insertNode(root, 70);
    tree.insertNode(root, 20);
    tree.insertNode(root, 40);
    tree.insertNode(root, 60);
    tree.insertNode(root, 80);

    // Inserting a node using iterative method
    tree.insertNewNode(root, 25);

    // Display traversals
    cout << "Preorder traversal: ";
    tree.preorder_traversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    tree.inorder_traversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder_traversal(root);
    cout << endl;

    // Search for a node using iteration
    int searchKey = 40;
    Node *foundNode = tree.searchNode(root, searchKey);
    if (foundNode)
    {
        cout << "Node with value " << searchKey << " found in the tree." << endl;
    }
    else
    {
        cout << "Node with value " << searchKey << " not found in the tree." << endl;
    }

    // Search for a node using recursion
    searchKey = 100;
    if (tree.searchRecursion(root, searchKey))
    {
        cout << "Node with value " << searchKey << " found in the tree using recursion." << endl;
    }
    else
    {
        cout << "Node with value " << searchKey << " not found in the tree using recursion." << endl;
    }

    // Determine the height of the tree
    cout << "Height of the tree: " << tree.height(root) << endl;

    // Level Order (Breadth-First) traversal
    cout << "Level order traversal (BFS): ";
    tree.printLevelOrderBFS(root);
    cout << endl;

    // Deleting a node
    cout << "Deleting node with value 30." << endl;
    root = tree.deleteNode(root, 30);

    // Inorder traversal after deletion to check the tree structure
    cout << "Inorder traversal after deleting node 30: ";
    tree.inorder_traversal(root);
    cout << endl;

    return 0;
}
