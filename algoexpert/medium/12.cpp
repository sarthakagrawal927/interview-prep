//  BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int n, vector<vector<int>> edges, vector<bool> visited, int start)
{
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int vertice = q.front();
        cout << vertice << " ";
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[vertice][i] && !visited[i] && i != vertice)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
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
    bfs(n, edges, visited, 0);
    cout << endl;
    return 0;
}