#include <iostream>
#include <stack>
using namespace std;

// Node definition
class Node {
    int data;
    Node *left, *right;
    public:
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    friend void zigzagTraversal(Node* root);
    friend Node* insertNode(Node *root, int val);
};

// Zigzag traversal function
void zigzagTraversal(Node *root) {
    if (!root) return; // Handle empty tree

    // Two stacks to store nodes of current and next levels
    stack<Node *> currentLevel;
    stack<Node *> nextLevel;

    // Push root node into the current level stack
    currentLevel.push(root);

    // Boolean flag to indicate the traversal direction
    bool leftToRight = true;

    while (!currentLevel.empty()) {
        Node *node = currentLevel.top();
        currentLevel.pop();

        if (node) {
            // Print the node's data
            cout << node->data << " ";

            // Push children into the next level stack in order
            if (leftToRight) {
                if (node->left) nextLevel.push(node->left);
                if (node->right) nextLevel.push(node->right);
            } else {
                if (node->right) nextLevel.push(node->right);
                if (node->left) nextLevel.push(node->left);
            }
        }

        // If the current level is empty, switch direction
        if (currentLevel.empty()) {
            swap(currentLevel, nextLevel); // Swap stacks
            leftToRight = !leftToRight;   // Reverse traversal direction
        }
    }
}

// Helper function to insert a node into a binary tree
Node* insertNode(Node *root, int val) {
    if (!root) return new Node(val);

    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else if (val > root->data) {
        root->right = insertNode(root->right, val);
    }

    return root;
}

int main() {
    Node *root = nullptr;

    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 10);

    cout << "Zigzag Order Traversal: ";
    zigzagTraversal(root);
    cout << endl;

    return 0;
}
