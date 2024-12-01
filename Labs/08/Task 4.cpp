#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

bool Identical(Node* t1, Node* t2){
    // if both trees are empty, they are identical
    if(!t1 && !t2){
        return true;
    }
    // if one of them is empty, they arent Identical
    if(!t1 || !t2){
        return false;
    }
    return (t1->data == t2->data) && Identical(t1->left, t2->left) && Identical(t1->right, t2->right);
}

bool isSubTree(Node* t1, Node* t2){
    // an empty tree is always a subtree
    if(!t2){
        return true;
    }
    // if t1 is empty and t2 is not, t2 cant be a subtree 
    if(!t1){
        return false;
    }
    if(Identical(t1, t2)){
        return true;
    }

    // otherwise recursively check in the left and right subtree
    return isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
}

int main() {
    // Construct Tree T1
    Node* t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);
    t1->left->left = new Node(4);
    t1->left->right = new Node(5);
    t1->right->left = new Node(6);
    t1->right->right = new Node(7);

    // Construct Tree T2
    Node* t2 = new Node(3);
    t2->left = new Node(6);
    t2->right = new Node(7);

    // Check if T2 is a subtree of T1
    if (isSubTree(t1, t2))
        cout << "T2 is a subtree of T1." << endl;
    else
        cout << "T2 is NOT a subtree of T1." << endl;

    return 0;
}