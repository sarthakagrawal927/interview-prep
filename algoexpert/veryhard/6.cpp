// Number of bniary tree toplogies
#include <bits/stdc++.h>
using namespace std;
// (2n)!/ (n!*(n+1)!)
int getTopologies(int n, vector<int> &a)
{
    int s = 0;
    if (a[n] != 0)
        return a[n];

    for (int i = 0; i < n; i++)
        s = s + getTopologies(i, a) * getTopologies(n - i - 1, a);

    a[n] = s;
    return s;
}

int getTopologiesIterative(int n, int s)
{
    vector<int> ans(n + 1, 0);
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ans[i] += ans[j] * ans[i - 1 - j];
        }
    }
    return ans[n];
}

int main()
{
    int n = 7;
    long int s = 0;
    vector<int> ans(n + 1, 0);
    ans[0] = 1;
    cout << getTopologiesIterative(n, s) << " ";
    cout << getTopologies(n, ans);

    return 11;
}