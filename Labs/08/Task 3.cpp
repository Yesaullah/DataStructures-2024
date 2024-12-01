#include <iostream>
#include <climits>

using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int d) : data(d), left(nullptr), right(nullptr) {}

    friend class BST;
};

class BST
{
    Node *root;
    int maxProfit;

    Node *addNode(Node *currentNode, int value)
    {
        if (!currentNode)
            return new Node(value);

        if (value < currentNode->data)
            currentNode->left = addNode(currentNode->left, value);
        else
            currentNode->right = addNode(currentNode->right, value);

        return currentNode;
    }

    int maxPathSum(Node *node)
    {
        if (!node)
            return 0;

        int leftSum = max(0, maxPathSum(node->left));
        int rightSum = max(0, maxPathSum(node->right));

        maxProfit = max(maxProfit, leftSum + rightSum + node->data);

        return node->data + max(leftSum, rightSum);
    }

public:
    BST() : root(nullptr), maxProfit(INT_MIN) {}

    int findMaxProfitPath()
    {
        if (!root)
            return 0;
        maxProfit = INT_MIN;
        maxPathSum(root);
        return maxProfit;
    }

    void insert(int value)
    {
        root = addNode(root, value);
    }
};

int main()
{
    BST tree;

    tree.insert(10);
    tree.insert(2);
    tree.insert(10);
    tree.insert(20);
    tree.insert(1);
    tree.insert(-25);
    tree.insert(3);
    tree.insert(4);

    int maxProfit = tree.findMaxProfitPath();

    cout << "The maximum profit path is: " << maxProfit << endl;

    return 0;
}
