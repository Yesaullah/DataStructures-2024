#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int key): data(key), left(nullptr), right(nullptr){}
};

void storeInOrder(Node* root, vector<int>& nodes){
    if(root == nullptr){
        return;
    }
    storeInOrder(root->left, nodes);
    nodes.push_back(root->data);
    storeInOrder(root->right, nodes);
}
Node* buildBalancedTree(vector<int>& nodes, int low, int high){
    if(low>high){
        return nullptr;
    }
    int mid = low + (high - low)/2;

    Node* root = new Node(nodes[mid]);

    root->left = buildBalancedTree(nodes, low, mid-1);
    root->right = buildBalancedTree(nodes, mid+1, high);

    return root;
}
Node* BalanceBST(Node* root){
    vector<int> nodes;

    storeInOrder(root, nodes);

    return buildBalancedTree(nodes, 0, nodes.size() - 1);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(15);
    root->right->right = new Node(20);

    Node* balancedRoot = BalanceBST(root);
    inorder(balancedRoot);
    cout << endl;

    return 0;
}