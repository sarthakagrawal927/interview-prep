// Iterative Inorder
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int val;
} Node;

void inorder(struct Node *root)
{
    struct Node *curr = root;
    stack<struct Node *> s;
    while (curr || s.size())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

struct Node *insertNode(struct Node *node, int val)
{
    if (!node)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
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
    struct Node *root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 19);
    inorder(root);

    return 11;
}