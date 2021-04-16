//NOT DONE

#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

/*
Min number of square values to get the number
*/
int minCountBrute(int n)
{
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    for (int i = 1; i < (int)sqrt(n); i++)
    {
        int mi = minCountBrute(n - i * i);
        ans = min(ans, mi);
    }
    return ans + 1;
}

int minCountMemo(int n, int *arr)
{
}

int minCountDP(int n)
{
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    cout << minCountBrute(n) << endl;

    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }

    // cout << minCountMemo(n, arr) << endl;

    // cout << minCountDP(n) << endl;

    return 0;
}
