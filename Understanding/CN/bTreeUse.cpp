#include <iostream>
#include <queue>
#include "bst.h"
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

int height(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root)
{
    //max distance between any  2 nodes -> not sum of left tree height and right tree height
    if (!root)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(max(option2, option3), option1);
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    pair<int, int> p;
    if (!root)
    {
        p.first = p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;

    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    p.first = height;
    p.second = diameter;
    return p;
}

//BST
int maximum(BinaryTreeNode<int> *root)
{
    if (!root)
        return -1;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if (!root)
        return 1e8;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

// O(n2)
bool isBST(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    return (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);
}

class isBSTreturn
{
public:
    bool isBST;
    int minimum, maximum;
};
// O(n)
isBSTreturn isBST_pro(BinaryTreeNode<int> *root)
{
    isBSTreturn output;
    if (!root)
    {
        output.isBST = true;
        output.minimum = 1e8;
        output.maximum = -1e8;
        return output;
    }
    isBSTreturn leftOutput = isBST_pro(root->left);
    isBSTreturn rightOutput = isBST_pro(root->right);
    output.minimum = min(root->data, min(rightOutput.minimum, leftOutput.minimum));
    output.maximum = max(root->data, max(rightOutput.maximum, leftOutput.maximum));
    output.isBST = (root->data > leftOutput.maximum) &&
                   (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    return output;
}

bool isBST_constraintCheck(BinaryTreeNode<int> *root, int minimum = -1e8, int maximum = 1e8)
{
    if (!root)
        return true;
    if (root->data < minimum || root->data > maximum)
        return false;

    return isBST_constraintCheck(root->left, minimum, root->data - 1) && isBST_constraintCheck(root->right, root->data, maximum);
}

bool findElement(BinaryTreeNode<int> *root)
{
}

void printInRange(BinaryTreeNode<int> *root, int start, int end)
{
}

BinaryTreeNode<int> *createTreeFromSortedArray(int arr[])
{
}

class node
{
public:
    int data;
    node *next;
};

node returnLLfromBST(BinaryTreeNode<int> *root)
{
}

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int element)
{
    if (!root)
        return NULL;
    if (root->data == element)
    {
        vector<int> *output = new vector<int>();
        output->push_back(element);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, element);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, element);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
        return NULL;
}

//Implement Avial Tree
int main()
{
    // int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    // int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // BinaryTreeNode<int> *root = buildTree(in, pre, 9);
    // BinaryTreeNode<int> *root = takeInputLevelWise();

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

    // printLevelWise(root);
    // cout << "Count: " << countNodes(root);
    // lb;
    // cout << "Diameter : " << diameter(root);
    // lb;
    // cout << "Diameter (faster) : " << heightDiameter(root).second;
    // lb;
    // cout << "IsBST : " << isBST(root);
    // lb;
    // cout << "IsBST  (faster) : " << isBST_pro(root).isBST;
    // lb;
    // cout << "IsBST by constraint check: " << isBST_constraintCheck(root);
    // lb;

    // vector<int> *path = getRootToNodePath(root, 9);
    // for (int i = 0; i < path->size(); i++)
    //     cout << path->at(i) << " ";
    // delete root;
    // delete path;

    BST b;
    b.insert(4);
    b.insert(5);
    b.insert(6);
    b.insert(8);
    b.insert(15);
    b.insert(2);
    b.insert(3);

    b.printTree();

    b.deleteData(6);
    b.deleteData(4);
    b.deleteData(5);
    b.insert(4);

    b.printTree();
    delete &b;
    return 0;
}