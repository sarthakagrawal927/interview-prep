// Traversaks
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
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void preorder(struct Node *root)
{
    if (!root)
        return;
    preorder(root->left);
    cout << root->val << " ";
    preorder(root->right);
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
    postorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    return 0;
}