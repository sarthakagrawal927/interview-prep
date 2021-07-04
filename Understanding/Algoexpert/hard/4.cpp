// Max Path
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int val = 8;
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

int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

pair<int, int> mps(struct Node *node)
{
    if (!node)
        return make_pair(0, 0);

    pair<int, int> left, right; //leftMaxSumAsBranch, leftMaxPathSum

    left = mps(node->left);
    right = mps(node->right);

    int maxChildSumAsBranch = max(left.first, right.first);
    int maxSumAsBranch = max(maxChildSumAsBranch, maxChildSumAsBranch + node->val);   //node val can be negative
    int maxSumAsRootNode = max(left.first + node->val + right.first, maxSumAsBranch); // checking for triangle
    int maxPathSum = max(left.second, right.second, maxSumAsRootNode);

    return make_pair(maxSumAsBranch, maxPathSum);
}

int main()
{
    struct Node *root = new struct Node();
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 14);
    insertNode(root, 13);
    insertNode(root, 19);

    inorder(root);
    cout << "\n"
         << mps(root).second;

    return 0;
}