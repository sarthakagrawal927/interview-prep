// Validate BST
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

bool validateBSTHelper(struct Node *root, int minV, int maxV)
{
    if (!root)
        return 1;

    if (root->val < minV || root->val > maxV)
        return false;

    bool leftIsValid = validateBSTHelper(root->left, minV, root->val);
    bool rightIsValid = validateBSTHelper(root->right, root->val, maxV);

    return leftIsValid && rightIsValid;
}

bool validateBST(struct Node *root)
{
    return validateBSTHelper(root, -1e8, 1e8);
}

int main()
{
    struct Node *root = NULL;
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 42);
    insertNode(root, 13);
    insertNode(root, 19);

    inorder(root);
    cout << endl;
    cout << validateBST(root);
    return 0;
}