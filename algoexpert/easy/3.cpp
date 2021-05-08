#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, vector<vector<int>> edges, vector<bool> visited, int start)
{
    cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < n; i++)
    {
        if (edges[start][i] && !visited[i]) // if edges exists and is not visited
            dfs(n, edges, visited, i);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        // edges[s][f] = 1;
    }
    vector<bool> visited(n, false);
    dfs(n, edges, visited, 0);
    cout << endl;
    return 0;
}