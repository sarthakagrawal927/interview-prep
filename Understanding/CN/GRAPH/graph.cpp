#include <iostream>
#include <queue>
using namespace std;

void printDFS(int **edges, int n, int start, bool *visited)
{
    cout << start << "  ";
    visited[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == start)
            continue;
        if (edges[start][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int start, bool *visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (q.size() > 0)
    {
        int v = q.front();
        cout << v << "  ";
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[v][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int j = 0; j < n; j++)
        visited[j] = 0;
    printDFS(edges, n, 0, visited);
    for (int j = 0; j < n; j++) // if graph not connected
    {
        if (!visited[j])
            return false;
    }
    delete[] visited;
    return true;
}

vector<int> getPathViaBFS(int **edges, int n, int start, int end, bool *visited)
{
    vector<int> ans;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    ans.push_back(start);
    while (q.size() > 0)
    {
        int v = q.front();
        q.pop();
        if (v == end)
        {
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            if (edges[v][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                if (v == end)
                {
                    return ans;
                }
            }
        }
    }
    return ans;
}

vector<int> getPathViaDFS(int **edges, int n, int start, int end, bool *visited)
{
}

vector<vector<int>> getComponents(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int j = 0; j < n; j++)
        visited[j] = 0;

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            ans[i].push_back(i);
            while (q.size() > 0)
            {
                int v = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (edges[v][j] && !visited[j])
                    {
                        q.push(j);
                        visited[j] = 1;
                        ans[i].push_back(j);
                    }
                }
            }
        }
    }
    return ans;
}

void DFS_0_BFS_1(int **edges, int n, int choice)
{
    bool *visited = new bool[n];
    for (int j = 0; j < n; j++)
        visited[j] = 0;
    for (int j = 0; j < n; j++) // if graph not connected
    {
        if (!visited[j])
            choice ? printBFS(edges, n, j, visited) : printDFS(edges, n, j, visited); //if choice = 1, printBFS
    }
    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1; //remove this in case of directed graphs
        // store weight instead of 1, if weighted graph
    }

    // DFS_0_BFS_1(edges, n, 0);
    // cout << endl;
    DFS_0_BFS_1(edges, n, 1);
    cout << endl;

    bool *visited = new bool[n];
    for (int j = 0; j < n; j++)
        visited[j] = 0;

    // solution for getting path
    vector<int> ans;
    ans = getPathViaBFS(edges, n, 0, 4, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    //getting components
    vector<vector<int>> ans1;
    // ans1 = getComponents(edges, n);

    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}