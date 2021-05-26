//  River Traversal
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MP make_pair
#define f first
#define s second

bool inBound(int i, int j, int n)
{
    return i < n && j < n && i >= 0 && j >= 0;
}

bool mainCheck(int i, int j, int n, vector<vector<bool>> visited, vector<vector<int>> edges)
{
    return inBound(i, j, n) && !visited[i][j] && edges[i][j];
}

int motion[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void PrintVisited(int n, vector<vector<bool>> visited)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int bfs(vector<vector<int>> edges, int n, vector<vector<bool>> visited, int i, int j)
{
    queue<pair<int, int>> q;
    q.push(MP(i, j));
    int size = 0;
    while (q.size())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (mainCheck(p.f, p.s, n, visited, edges))
        {
            // cout << p.f << " " << p.s << endl;

            visited[p.f][p.s] = 1;
            size++;
            for (int i = 0; i < 4; i++)
            {
                if (mainCheck(p.f + motion[i][0], p.s + motion[i][1], n, visited, edges))
                {
                    q.push(MP(p.f + motion[i][0], p.s + motion[i][1]));
                }
                else if (inBound(p.f + motion[i][0], p.s + motion[i][1], n))
                    visited[p.f + motion[i][0]][p.s + motion[i][1]] = 1;
            }
        }
        // PrintVisited(n, visited);
    }
    return size;
}

int main()
{
    vector<vector<int>> river = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1}};

    int n = river.size();

    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    int max_here = 0, maxi = 0;
    // PrintVisited(n, visited);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (river[i][j])
            {
                if (!visited[i][j])
                {
                    // cout << "Call\n";
                    max_here = bfs(river, n, visited, i, j);
                    maxi = max(maxi, max_here);
                }
            }
            else
                visited[i][j] = 1;

    // PrintVisited(n, visited);
    cout << maxi << endl;
    return 0;
}