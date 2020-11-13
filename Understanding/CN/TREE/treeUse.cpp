#include "tree.h"
#include <queue>
void printTree(TreeNode<int> *root)
{
    if (!root) // only in case we get root as null in start, else it never reaches it
        return;
    cout << root->data << " : "; //no need for explicit base case
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void levelOrderPrintTreeForUnderstanding(TreeNode<int> *root)
{
    if (!root)
        return;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        root = pendingNodes.front();
        cout << root->data << " : ";
        pendingNodes.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ", ";
            pendingNodes.push(root->children[i]);
        }
        cout << endl;
    }
}

void levelOrderPrintTree(TreeNode<int> *root)
{
    if (!root)
        return;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    cout << root->data << ", ";
    while (!pendingNodes.empty())
    {
        root = pendingNodes.front();
        pendingNodes.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ", ";
            pendingNodes.push(root->children[i]);
        }
    }
    cout << endl;
}

void preOrder(TreeNode<int> *root)
{
    if (!root)
        return;
    cout << root->data << ", ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root)
{
    if (!root)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << ", ";
}

TreeNode<int> *inputTree()
{
    int rootData, n;
    cout << "Enter data for node \n";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout << "Enter number of child for node " << rootData << ": \n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = inputTree();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *inputTreeByLevel()
{
    int rootData, numChild;
    cout << "Enter data for node \n";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root); // start by root in queue

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop(); // take and remove the first element in queue
        cout << "Enter number of child for node " << front->data << ": \n";
        cin >> numChild;
        for (int i = 0; i < numChild; i++) // input all children for the node
        {
            cout << "Enter " << i << "th child for " << front->data << ": \n";
            cin >> rootData;
            TreeNode<int> *child = new TreeNode<int>(rootData); // allocate dynamically as static variables are killed when out of scope

            front->children.push_back(child); // add the children in both queue and attach them to tree
            pendingNodes.push(child);
        }
    }
    return root;
}

int countNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int sumNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumNodes(root->children[i]);
    }
    return sum;
}

int maximumNode(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int maxi = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxi = max(maxi, maximumNode(root->children[i]));
    }
    return maxi;
}

int heightOfTree(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        height = max(height, heightOfTree(root->children[i]));
    }
    return height + 1;
}

void printAtDepth(TreeNode<int> *root, int depth)
{
    if (!root)
        return;
    if (depth == 0)
    {
        cout << root->data << ", ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtDepth(root->children[i], depth - 1);
    }
}

int numberOfLeaf(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int count = 0;
    if (root->children.size() == 0)
        return 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += numberOfLeaf(root->children[i]);
    }
    return count;
}

void deleteTree(TreeNode<int> *root)
{
    // simple post traversal - delete children first
    if (!root)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    TreeNode<int> *root;
    //tree
    //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    root = inputTreeByLevel();
    cout << "Tree" << endl;
    levelOrderPrintTreeForUnderstanding(root);
    cout << "Level Order" << endl;
    levelOrderPrintTree(root);
    cout << "Pre Order" << endl;
    preOrder(root);
    cout << endl;
    cout << "Post Order" << endl;
    postOrder(root);
    cout << endl;

    cout << "Number of Nodes: " << countNodes(root) << "\n"
         << "Sum of Nodes: " << sumNodes(root) << "\n"
         << "Maximum Node: " << maximumNode(root) << "\n"
         << "Height of Tree: " << heightOfTree(root) << "\n"
         << "Number of Leaf Nodes: " << numberOfLeaf(root) << "\n";

    cout << "Elements at depth 2:\n ";
    printAtDepth(root, 2);
    //deleteTree(root);
    delete root;
}