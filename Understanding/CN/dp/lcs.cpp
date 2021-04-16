// Longest common subsequence
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int LCSBrute(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
        return 0;

    if (s[0] == t[0])
    {
        return 1 + LCSBrute(s.substr(1), t.substr(1));
    }
    else
    {
        int a = LCSBrute(s.substr(1), t);
        int b = LCSBrute(s, t.substr(1));
        return max(a, b);
    }
}

int LCSMemo(string s, string t, int **ans)
{
    if (s.size() == 0 || t.size() == 0)
        return 0;
    int n = s.size();
    int m = t.size();

    if (ans[n][m] != -1)
        return ans[n][m];

    if (s[0] == t[0])
    {
        ans[n - 1][m - 1] = LCSMemo(s.substr(1), t.substr(1), ans);
        ans[n][m] = 1 + ans[n - 1][m - 1];
    }
    else
    {
        ans[n - 1][m] = LCSMemo(s.substr(1), t, ans);
        ans[n][m - 1] = LCSMemo(s, t.substr(1), ans);
        ans[n][m] = max(ans[n - 1][m], ans[n][m - 1]);
    }
    return ans[n][m];
}

int LCSDP(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[m + 1];
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else
                arr[i][j] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1]) // or s[n-i] == t[m-j]
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    return arr[n][m];
}

int main(int argc, char const *argv[])
{
    string s = "afasefasd";
    string t = "aasdas";

    cout << LCSBrute(s, t) << endl;

    int n = s.size();
    int m = t.size();

    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[m + 1];
        for (int j = 0; j <= m; j++)
            arr[i][j] = -1;
    }

    cout << LCSMemo(s, t, arr) << endl;

    cout << LCSDP(s, t) << endl;

    return 0;
}
