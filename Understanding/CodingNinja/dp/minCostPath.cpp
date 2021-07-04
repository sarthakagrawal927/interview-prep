#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int shortestPathBrute(int **input, int n, int m, int i, int j)
{
    if (i == (n - 1) && j == (m - 1))
        return input[i][j];

    if (i == n || j == m)
        return INT_MAX;

    int x = (i < n && j < m) ? shortestPathBrute(input, n, m, i + 1, j + 1) : INT_MAX;
    int y = (j < m) ? shortestPathBrute(input, n, m, i, j + 1) : INT_MAX;
    int z = (i < n) ? shortestPathBrute(input, n, m, i + 1, j) : INT_MAX;

    return min(x, min(y, z)) + input[i][j];
}

int shortestPathMemo(int **input, int n, int m, int i, int j, int **ans)
{
    if (i == (n - 1) && j == (m - 1))
        return input[i][j];

    if (i >= n || j >= m)
        return INT_MAX;

    if (ans[i][j] != -1)
        return ans[i][j];

    int x = shortestPathMemo(input, n, m, i + 1, j + 1, ans);
    if (x < INT_MAX)
        ans[i + 1][j + 1] = x;
    int y = shortestPathMemo(input, n, m, i, j + 1, ans);
    if (y < INT_MAX)
        ans[i][j + 1] = y;
    int z = shortestPathMemo(input, n, m, i + 1, j, ans);
    if (z < INT_MAX)
        ans[i + 1][j] = z;

    ans[i][j] = min(x, min(y, z)) + input[i][j];
    return ans[i][j];
}

int shortestPathDP(int **input, int n, int m)
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    int x, y, z;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            // Conditional as for last row and column, there might not exist alot of options XD
            x = ((i + 1) < n) ? arr[i + 1][j] : INT_MAX;
            y = ((j + 1) < m) ? arr[i][j + 1] : INT_MAX;
            z = (((i + 1) < n) && ((j + 1) < m)) ? arr[i + 1][j + 1] : INT_MAX;
            if ((i == (n - 1)) && (j == (m - 1)))
                arr[i][j] = input[n - 1][m - 1];
            else
                arr[i][j] = min(x, min(y, z)) + input[i][j];
        }
    }

    return arr[0][0];
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    cout << shortestPathBrute(arr, n, m, 0, 0) << endl;

    int **ans = new int *[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = new int[m];
        for (int j = 0; j < m; j++)
            ans[i][j] = -1;
    }

    cout << shortestPathMemo(arr, n, m, 0, 0, ans) << endl;

    cout << shortestPathDP(arr, n, m) << endl;

    return 0;
}
