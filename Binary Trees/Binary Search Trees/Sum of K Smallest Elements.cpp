#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr){}
    friend class BinarySearchTree;
};

class BinarySearchTree{
    public:
    Node* root;
    BinarySearchTree(): root(nullptr){}

    Node* addNode(Node* root, int d){
        if(root == nullptr){
            return new Node(d);
        }
        if(d<root->data){
            root->left = addNode(root->left, d);
        }
        else{
            root->right = addNode(root->right, d);
        }
        return root;
    }

    int sumOfKSmallest(Node* root, int k){
        int sum = 0;
        int count = 0;
        sumKSmallestUntil(root, k, count, sum);
        return sum;
    } 
    void sumKSmallestUntil(Node* root, int k, int& count, int& sum){
        if(!root || count>=k){
            return;
        }

        sumKSmallestUntil(root->left, k, count, sum);
        if(count<k){
            sum+= root->data;
            count++;
        }

        sumKSmallestUntil(root->right, k, count, sum);
    }
};

int main(){
    BinarySearchTree tree;

    tree.root = tree.addNode(tree.root, 50);
    tree.addNode(tree.root, 30);
    tree.addNode(tree.root, 20);
    tree.addNode(tree.root, 40);
    tree.addNode(tree.root, 70);
    tree.addNode(tree.root, 60);
    tree.addNode(tree.root, 80);

    int k = 3;

    int sum = tree.sumOfKSmallest(tree.root, k);
    cout << "Sum of " << k << " smallest elements: " << sum << endl;

    return 0;
}