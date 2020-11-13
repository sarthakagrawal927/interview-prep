#include <vector>
#include <iostream>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children; // automatically assumes that children will contain same datatype as parent

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode() // destructor function OP, delete root will call this
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i]; // making this recursive
        }
    }
};
