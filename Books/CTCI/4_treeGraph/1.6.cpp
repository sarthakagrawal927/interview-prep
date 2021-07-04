#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right, *parent;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    ~BinaryTreeNode() // destructor function OP, delete root will call this
    {
        delete left;
        delete right;
    }
};

void inorder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

BinaryTreeNode<int> *insertNode(BinaryTreeNode<int> *node, int data)
{
    BinaryTreeNode<int> *temp;
    if (!node)
    {
        BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
        return newNode;
    }
    if (node->data > data)
    {
        temp = insertNode(node->left, data);
        temp->parent = node;
        node->left = temp;
    }
    else
    {
        temp = insertNode(node->right, data);
        temp->parent = node;
        node->right = temp;
    }
    return node;
}

BinaryTreeNode<int> *returnSuccessor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *find)
{
    if (!root || !find)
        return NULL;
    BinaryTreeNode<int> *temp;
    if (find->right)
    {
        temp = find->right;
        while (temp->left)
            temp = temp->left;
        return temp;
    }
    else
    {
        temp = find->parent;
        while (temp)
        {
            temp = temp->parent;
            if (temp->left)
                return temp;
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root;
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 43);
    root = insertNode(root, 16);
    root = insertNode(root, 1);
    root = insertNode(root, 19);
    root = insertNode(root, 24);
    root = insertNode(root, 14);

    cout << root->right->left->right->right->data << " ";
    cout << returnSuccessor(root, root->right->left->right->right)->data;
    return 0;
}