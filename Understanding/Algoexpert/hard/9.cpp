// Knapsack

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> weight = {2, 3, 6, 7};
    vector<int> worth = {1, 4, 5, 6};
    int w = 10;
    int n = worth.size();
    vector<vector<int>> knap(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                knap[i][j] = max(knap[i - 1][j], (knap[i - 1][j - weight[i - 1]] + worth[i - 1]));
            }
            else
                knap[i][j] = knap[i - 1][j];
            cout << knap[i][j] << " ";
        }
        cout << endl;
    }
    cout << knap[n][w];
    return 0;
}
