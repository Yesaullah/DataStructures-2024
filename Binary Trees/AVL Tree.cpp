#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    int height;

public:
    Node(int d) : data(d), left(nullptr), right(nullptr), height(1) {}

    friend class AVL;
};

class AVL
{
    Node *root;

    int get_height(Node *node)
    {
        return node ? node->height : 0;
    }
    int get_balanceFactor(Node *node)
    {
        return node ? get_height(node->left) - get_height(node->right) : 0;
    }
    Node *RR(Node *node)
    {
        Node *child = node->right;
        node->right = child->left;
        child->left = node;

        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        child->height = max(get_height(child->left), get_height(child->right)) + 1;

        return child;
    }
    Node *LL(Node *node)
    {
        Node *child = node->left;
        node->left = child->right;
        child->right = node;

        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        child->height = max(get_height(child->left), get_height(child->right)) + 1;

        return child;
    }

    Node *insertNode(Node *node, int value)
    {
        if (!node)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }
        else
        {
            // duplicate values are not allowed so return the same node
            return node;
        }

        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        int balancefactor = get_balanceFactor(node);

        // checking for rotations
        // LL-Rotation
        if (balancefactor > 1 && value < node->left->data)
        {
            return LL(node);
        }
        // RR-Rotation
        if (balancefactor < -1 && value > node->right->data)
        {
            return RR(node);
        }
        // LR-Rotation
        if (balancefactor > 1 && value > node->left->data)
        {
            node->left = RR(node->left);
            return LL(node);
        }
        // RL-Rotation
        if (balancefactor < -1 && value < node->right->data)
        {
            node->right = LL(node->right);
            return RR(node);
        }

        return node;
    }

    // inorder traversal
    void inOrderTrversal(Node *node)
    {
        if (node)
        {
            inOrderTrversal(node->left);
            cout << node->data << " ";
            inOrderTrversal(node->right);
        }
    }

    // smallest value from the left subtree
    Node *min_value(Node *node)
    {
        Node *current = node;
        while (current->left)
        {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *node, int key)
    {
        if (!node)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else
        {
            if (!node->left || !node->right)
            {
                Node *temp = node->left ? node->left : node->right;

                if (!temp)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;

                delete temp;
            }
            else
            {
                Node *temp = min_value(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (!node)
            return node;

        node->height = 1 + max(get_height(node->left), get_height(node->right));

        int balance = get_balanceFactor(node);

        // Perform rotations if needed
        // Left-Left Case
        if (balance > 1 && get_balanceFactor(node->left) >= 0)
            return RR(node);

        // Left-Right Case
        if (balance > 1 && get_balanceFactor(node->left) < 0)
        {
            node->left = LL(node->left);
            return RR(node);
        }

        // Right-Right Case
        if (balance < -1 && get_balanceFactor(node->right) <= 0)
            return LL(node);

        // Right-Left Case
        if (balance < -1 && get_balanceFactor(node->right) > 0)
        {
            node->right = RR(node->right);
            return LL(node);
        }

        return node;
    }

    // Preorder Traversal
    void preOrderTraversal(Node *node)
    {
        if (node)
        {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    public:
    AVL() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void displayInorder() {
        cout << "Inorder traversal: ";
        inOrderTrversal(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVL tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "AVL tree after insertions:" << endl;
    tree.displayInorder();
    tree.displayPreorder();

    tree.deleteNode(20);

    cout << "\nAVL tree after deleting 20:" << endl;
    tree.displayInorder();
    tree.displayPreorder();

    return 0;
}