#include <iostream>
#include <queue>
#include "binaryTree.h"
#define lb cout << "\n"
using namespace std;

//Inputting
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "ENter data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftC = takeInput();
    BinaryTreeNode<int> *rightC = takeInput();
    root->left = leftC;
    root->right = rightC;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "ENter data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *lc = new BinaryTreeNode<int>(leftChildData);
            front->left = lc;
            pendingNodes.push(lc);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rc = new BinaryTreeNode<int>(rightChildData);
            front->right = rc;
            pendingNodes.push(rc);
        }
    }
    return root;
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
        return NULL;
    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i < inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}
//Printing
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        if (front->left)
        {
            cout << "L" << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        if (front->right)
        {
            cout << "R" << front->right->data << " ";
            pendingNodes.push(front->right);
        }
        cout << endl;
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

void preOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//Baby tasks
int countNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main()
{
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    BinaryTreeNode<int> *root = buildTree(in, pre, 9);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

    printLevelWise(root);
    cout << "Count: " << countNodes(root);
    lb;
    cout << "Inorder : "
         << "\n";
    inOrder(root);
    lb;
    cout << "preorder : "
         << "\n";
    preOrder(root);
    lb;
    cout << "postorder : "
         << "\n";
    postOrder(root);
    lb;
    delete root;
    return 0;
}