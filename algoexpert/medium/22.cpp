// Create Suffix trie

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    char val;
    vector<struct Node *> kids;
} Node;

struct Node *isAKid(vector<struct Node *> kids, char c)
{
    for (int i = 0; i < kids.size(); i++)
    {
        if (kids[i]->val == 'c')
            return kids[i];
    }
    return NULL;
}

void insertSubstring(struct Node *root, string s)
{
    struct Node *temp;
    // cout << s << " ";
    for (int i = 0; i < s.size(); i++)
    {
        char letter = s[i];
        struct Node *t = isAKid(temp->kids, letter);
        if (!t)
            t->val = s[i];
        temp = t;
    }
    temp->val = '*';
}

void insert(struct Node *root, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        insertSubstring(root, s.substr(i, s.size()));
    }
}

int main()
{
    string s = "abcdc";
    struct Node *head = new struct Node;
    head->val = 'o';
    head->kids = {};
    insert(head, s);
}
