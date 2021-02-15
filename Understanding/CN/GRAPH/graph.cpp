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
}

vector<int> getPathViaDFS(int **edges, int n, int start, int end, bool *visited)
{
}

vector<vector<int>> getComponents(int **edges, int n)
{
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

    DFS_0_BFS_1(edges, n, 0);
    cout << endl;
    DFS_0_BFS_1(edges, n, 1);
    cout << endl;

    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}