class Solution
{
public:
    bool kahnAlgo(vector<vector<int>> &adj, int n, vector<int> &indegree, vector<int> &ans)
    {
        queue<int> q;

        // adding nodes w 0 dependencies
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto a : adj[curr]) // removing it as dependency from other nodes
            {
                indegree[a] -= 1;
                if (indegree[a] == 0) // if no dependency
                    q.push(a);
            }
            ans.push_back(curr);
            count++;
        }
        return count == n; // all nodes are covered or not
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1; // number of dependencies
        }

        vector<int> ans;
        if (kahnAlgo(adj, numCourses, indegree, ans))
            return ans;
        else
            return {};
    }
};