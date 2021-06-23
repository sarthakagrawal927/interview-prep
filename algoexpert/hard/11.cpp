// Topological sort]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// vector<int> dfs() {}

// vector<int> bfs() {}

void printGraph(vector<vector<int>> g, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n = 4, e = 5; // number of jobs & number of prerequisites
    vector<bool> visited(n, false);
    vector<vector<int>> graph(n, vector<int>(n, 0));
    int job, pre;
    for (int i = 0; i < e; i++)
    { //1 2 4 2 3 2 4 3 1 3
        cin >> job >> pre;
        graph[job - 1][pre - 1] = 1;
    }
    printGraph(graph, n);
    return 0;
}
