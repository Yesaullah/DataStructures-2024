#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(char d)
    {
        data = d;
        left = right = NULL;
    }
    friend class BinaryTree;
};
class BinaryTree
{
    TreeNode *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    // to deserialize and form a tree
    void addNode(char d)
    {
        TreeNode *n = new TreeNode(d);
        if (root == NULL)
        {
            root = n;
            return;
        }
        else
        {
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left == NULL)
                {
                    cur->left = n;
                    return;
                }
                else
                {
                    q.push(cur->left);
                }
                if (cur->right == NULL)
                {
                    cur->right = n;
                    return;
                }
                else
                {
                    q.push(cur->right);
                }
            }
        }
    }
    /// serialize
    string LevelOrderTraversal()
    {
        string str = "";
        if (root == NULL)
        {
            return "";
        }
        else
        {
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *cur = q.front();
                q.pop();
                str += cur->data;
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
        return str;
    }
    void printLevelOrder()
    {

        if (root == NULL)
        {
            return;
        }
        else
        {
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *cur = q.front();
                q.pop();
                cout << cur->data;
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
    }
};

int main()
{
    BinaryTree tree;
    // first a tree of string is formed
    tree.addNode('Y');
    tree.addNode('e');
    tree.addNode('s');
    tree.addNode('a');
    tree.addNode('u');
    tree.addNode('l');
    tree.addNode('l');
    tree.addNode('a');
    tree.addNode('h');

    cout<<"Tree 1: "<<endl;
    tree.printLevelOrder();

    string str = tree.LevelOrderTraversal();

    cout << "\nTree 1 string: " << str << endl;

    BinaryTree tree2;
    // reconstructing the tree
    for (char c : str)
    {
        tree2.addNode(c);
    }
    cout <<""<< endl;
    cout<<"Tree 2: "<<endl;
    tree2.printLevelOrder();
}