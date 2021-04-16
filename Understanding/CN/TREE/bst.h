
#include "binaryTree.h"
#include <algorithm>
class BST
{
private:
    BinaryTreeNode<int> *root;

    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (!node)
            return false;
        if (node->data == data)
            return true;
        else if (data < node->data)
        {
            return hasData(data, node->left);
        }
        else
            return hasData(data, node->right);
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *root)
    {
        if (!root)
        {
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if (data < root->data)
            root->left = insert(data, root->left);
        else
        {
            root->right = insert(data, root->right);
        }
        return root;
    }

    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *root)
    {
        if (!root)
        {
            return NULL;
        }
        if (data < root->data)
            root->left = deleteData(data, root->left);
        else if (data > root->data)
        {
            root->right = deleteData(data, root->right);
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = root->right;

                while (minNode->left != NULL)
                    minNode = minNode->left;

                int rightMin = minNode->data;

                root->right = deleteData(rightMin, root->right);
                root->data = rightMin;
                return root;
            }
        }
    }

    void printTree(BinaryTreeNode<int> *root)
    {
        if (!root)
            return;
        cout << root->data << ": ";
        if (root->left)
            cout << "L" << root->left->data;
        if (root->right)
            cout << "R" << root->right->data;

        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }
    void deleteData(int data)
    {
        this->root = deleteData(data, this->root);
    }
    bool hasData(int data)
    {
        return hasData(data, this->root);
    }
    void printTree()
    {
        printTree(root);
    }
};