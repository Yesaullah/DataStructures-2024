#include <iostream>
#include <vector>
using namespace std;

// Define the structure of a BST node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to perform in-order traversal and store elements in a vector
void inorderTraversal(TreeNode* root, vector<int>& elements) {
    if (!root) return;

    inorderTraversal(root->left, elements);
    elements.push_back(root->val);
    inorderTraversal(root->right, elements);
}

// Function to merge two sorted arrays
vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }

    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }

    return merged;
}

// Function to construct a balanced BST from a sorted array
TreeNode* sortedArrayToBST(const vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to merge two BSTs
TreeNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    vector<int> elements1, elements2;

    // Perform in-order traversals to get sorted arrays
    inorderTraversal(root1, elements1);
    inorderTraversal(root2, elements2);

    // Merge the two sorted arrays
    vector<int> mergedArray = mergeArrays(elements1, elements2);

    // Construct a balanced BST from the merged sorted array
    return sortedArrayToBST(mergedArray, 0, mergedArray.size() - 1);
}

// Helper function to print the BST in-order
void printInOrder(TreeNode* root) {
    if (!root) return;

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Main function to test the mergeBSTs function
int main() {
    // First BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    // Second BST
    TreeNode* root2 = new TreeNode(7);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(8);

    // Merge the two BSTs
    TreeNode* mergedRoot = mergeBSTs(root1, root2);

    // Print the merged BST in-order
    cout << "Merged BST (In-order Traversal): ";
    printInOrder(mergedRoot);
    cout << endl;

    return 0;
}
