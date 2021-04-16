#include <iostream>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

/*
GIven Height find total possible number of balanced trees of that height
*/

int countBTBrute(int n)
{
    if (n <= 1)
        return 1;
    int a1 = countBTBrute(n - 1);
    int a2 = countBTBrute(n - 2);
    int mod = (int)pow(10, 9) + 7;

    return ((a1 % mod * a1 % mod) % mod + (2 * a2 % mod * a1 % mod) % mod) % mod;
}

int countBTMemo(int n, int *arr)
{
}

int countBTDP(int n)
{
}

int main(int argc, char const *argv[])
{
    int h = atoi(argv[1]);
    cout << countBTBrute(h) << endl;

    return 0;
}
