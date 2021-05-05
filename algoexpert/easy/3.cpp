#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int e, vector<vector<int>> edges, vector<bool> found)
{
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n);

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    vector<bool> found(n, false);
    cout << endl;
    return 0;
}