#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int knapsackBrute(int n, int *w, int *v, int maxi)
{
    if (n == 0 || maxi == 0)
        return 0;

    if (w[0] > maxi)
    {
        return knapsackBrute(n - 1, w + 1, v + 1, maxi);
    }

    int x = knapsackBrute(n - 1, w + 1, v + 1, maxi - w[0]) + v[0]; //added
    int y = knapsackBrute(n - 1, w + 1, v + 1, maxi);               // not added
    return max(x, y);
}

int knapsackMemo(int n, int *arr)
{
}

int knapsackDP(int n)
{
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    int maxi = atoi(argv[2]);
    int *w = new int[n];
    int *v = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << knapsackBrute(n, w, v, maxi) << endl;

    // int *arr = new int[n + 1];
    // for (int i = 0; i < n + 1; i++)
    // {
    //     arr[i] = -1;
    // }

    // cout << knapsackMemo(n, arr) << endl;

    // cout << knapsackDP(n) << endl;

    return 0;
}
