vector<int> solve(vector<vector<int>> &lists)
{
    vector<int> ans;
    for (int i = 0; i < lists.size(); i++)
    {
        for (int j = 0; j < lists[i].size(); j++)
        {
            ans.push_back(lists[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}