/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        else if ((node->neighbors).size() == 0)
            return node;
        else
        {
            map<Node *, Node *> m; // to keep the original and clone together
            queue<Node *> q;       // to use for BFS
            q.push(node);
            Node *newNode = new Node(node->val);
            m[node] = newNode;
            while (!q.empty())
            {
                Node *u = q.front();
                q.pop();
                vector<Node *> v = u->neighbors;
                // Visiting all neighbors
                for (int i = 0; i < v.size(); i++)
                {
                    if (m[v[i]] == NULL)
                    { // Node not present
                        newNode = new Node(v[i]->val);
                        m[v[i]] = newNode;
                        q.push(v[i]);
                    }
                    m[u]->neighbors.push_back(m[v[i]]);
                }
            }
            return m[node];
        }
    }
};