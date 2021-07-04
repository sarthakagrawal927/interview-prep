class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;
    int target = 0;
    void dfs(vector<vector<int>> graph, int currNode)
    {
        temp.push_back(currNode);

        if (currNode == target)
            ans.push_back(temp);
        else
        {
            for (int i = 0; i < graph[currNode].size(); i++)
                dfs(graph, graph[currNode][i]);
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        target = graph.size() - 1;
        dfs(graph, 0);
        return ans;
    }
};