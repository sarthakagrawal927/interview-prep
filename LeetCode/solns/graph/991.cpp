class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> vis(N + 1, 0);
        vector<int> tr(N + 1, 0);

        for (int i = 0; i < trust.size(); i++)
        {
            vis[trust[i][0]] = 1;
            tr[trust[i][1]]++;
        }

        int count = N - 1; // everybody trusts the town judges so N-1 people trust him
        for (int i = 1; i <= N; i++)
            if (vis[i] == 0 && tr[i] == count)
                return i;

        return -1;
    }
};