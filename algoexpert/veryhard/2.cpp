// Max profit with k transactions
#include <bits/stdc++.h>
using namespace std;

// O(nk) time and space
int getmaxProfit(int k, vector<int> val)
{
    int n = val.size();
    if (n == 0)
        return 0;
    vector<vector<int>> profits(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; i++) // transaction number
    {
        int maxThusFar = -1e8;
        for (int j = 1; j < n; j++) // prices
        {
            maxThusFar = max(maxThusFar, profits[i - 1][j - 1] - val[j - 1]);
            profits[i][j] = max(profits[i][j - 1], maxThusFar + val[j]);
        }
    }
    return profits[k][n - 1];
}

// O(nk) time and O(n) space
int getmaxProfitBetter(int k, vector<int> val)
{
    int n = val.size();
    if (n == 0)
        return 0;
    vector<int> evenProfits(n, 0), oddProfits(n, 0), currentProfits(n, 0), prevProfits(n, 0);

    for (int i = 1; i <= k; i++) // transaction number
    {
        int maxThusFar = -1e8;

        // Swapping the array, here the answer is not coming right as it is copying the value , instead of liocation
        currentProfits = i % 2 ? oddProfits : evenProfits;
        prevProfits = i % 2 ? evenProfits : oddProfits;

        for (int j = 1; j < n; j++) // prices
        {
            maxThusFar = max(maxThusFar, prevProfits[j - 1] - val[j - 1]);
            currentProfits[j] = max(currentProfits[j - 1], maxThusFar + val[j]);
        }
    }
    cout << currentProfits[n - 1] << prevProfits[n - 1] << endl;
    return (k % 2 == 1 ? oddProfits[n - 1] : evenProfits[n - 1]);
}

int main()
{
    int k = 2;
    vector<int> val = {5, 11, 3, 50, 60, 90};
    cout << getmaxProfit(k, val);
    cout << getmaxProfitBetter(k, val);

    return 0;
}