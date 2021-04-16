#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
/*
* possible op:
1) -1
2) /2
3) /3
*/

int minStepBrute(int n)
{
    if (n == 1)
        return 0;
    int x = minStepBrute(n - 1);
    int y = (n % 2 == 0) ? minStepBrute(n / 2) : INT_MAX;
    int z = (n % 3 == 0) ? minStepBrute(n / 3) : INT_MAX;

    return min(min(x, y), z) + 1;
}

int minStepMemo(int n, int *arr)
{
    if (n == 1)
    {
        arr[n] = 0;
        return 0;
    }
    //arr[i] = min number of steps to reach i

    if (arr[n - 1] == -1)
        arr[n - 1] = minStepMemo(n - 1, arr);

    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        if (arr[n / 2] == -1)
            arr[n / 2] = minStepMemo(n / 2, arr);
        y = arr[n / 2];
    }

    if (n % 3 == 0)
    {
        if (arr[n / 3] == -1)
            arr[n / 3] = minStepMemo(n / 3, arr);
        z = arr[n / 3];
    }

    arr[n] = min(min(arr[n - 1], y), z) + 1;
    return arr[n];
}

int minStepDP(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;
    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = INT_MAX;
    }
    for (int i = 1; i < n; i++)
    {
        if (ans[i + 1] > (ans[i] + 1))
            ans[i + 1] = ans[i] + 1;

        if (2 * i <= n)
        {
            if (ans[2 * i] > (ans[i] + 1))
                ans[2 * i] = ans[i] + 1;
        }
        if (3 * i <= n)
        {
            if (ans[3 * i] > (ans[i] + 1))
                ans[3 * i] = ans[i] + 1;
        }
    }
    return ans[n];
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    // cout << minStepBrute(n) << endl;

    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }

    cout << minStepMemo(n, arr) << endl;

    cout << minStepDP(n) << endl;

    return 0;
}
