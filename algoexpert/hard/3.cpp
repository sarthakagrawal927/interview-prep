// Construction of BST
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int val;
} Node;

void inorder(struct Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

bool find(struct Node *root, int target)
{
    int l = INT16_MAX, r = INT16_MAX;
    struct Node *copy = root;
    while (copy)
    {
        if (copy->val == target)
            return 1;

        if (target < copy->val)
            copy = copy->left;
        else if (target > copy->val)
            copy = copy->right;
    }
    return 0;
}

struct Node *insertNode(struct Node *node, int val)
{
    if (!node)
    {
        struct Node *newNode = new struct Node();
        newNode->left = newNode->right = NULL;
        newNode->val = val;
        return newNode;
    }
    if (node->val > val)
        node->left = insertNode(node->left, val);
    else
        node->right = insertNode(node->right, val);
    return node;
}

int getMin(struct Node *root)
{
    struct Node *copy = root;
    while (copy->left)
        copy = copy->left;
    return copy->val;
}

void deleteNode(struct Node *root, int target)
{
    // cout << target;
    int l = INT16_MAX, r = INT16_MAX;
    struct Node *copy = root, *parentNode;
    while (copy)
    {
        if (copy->val == target) // Found, now delete
        {
            // cout << "found";
            // cout << parentNode->val;

            if (copy->left && copy->right) // both child node
            {
                copy->val = getMin(copy->right);
                deleteNode(copy->right, copy->val);
            }

            else if (!parentNode) //rootnode
            {
                if (copy->left)
                    copy = copy->left;
                else if (copy->right)
                    copy = copy->right;
            }

            else if (parentNode->left == copy) // is left child
            {
                parentNode->left = (copy->left) ? copy->left : copy->right ? copy->right
                                                                           : NULL;
                return;
            }
            else if (parentNode->right == copy) // is right child
            {
                parentNode->right = (copy->left) ? copy->left : copy->right ? copy->right
                                                                            : NULL;
                return;
            }
            else
            { // single node
                copy = NULL;
                return;
            }
        }
        if (target < copy->val)
        {
            parentNode = copy;
            copy = copy->left;
        }
        else if (target > copy->val)
        {
            parentNode = copy;
            copy = copy->right;
        }
    }
}

int main()
{
    struct Node *root = new struct Node();
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 42);
    insertNode(root, 13);
    insertNode(root, 19);
    inorder(root);
    cout << endl;
    deleteNode(root, 15);
    inorder(root);

    cout << '\n'
         << find(root, 15);
    return 0;
}