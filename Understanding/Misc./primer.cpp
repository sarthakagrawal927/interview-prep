//Sieve of Eratosthenes
#include <iostream>
#include <numeric>
#include <vector>
#include <math.h>

using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)

int main()
{
    int n;
    cin >> n;
    int p_max = sqrt(n);
    vector<int> a;
    rep(i, 2, n + 1) a.push_back(i);
    rep(i, 2, p_max)
    {
        int remove = i * i;
        while (remove <= n)
        {
            a[remove - 2] = 0;
            remove += i;
        }
    }
    cout << endl;
    rep(i, 0, n - 1) if (a[i] != 0) cout << a[i] << " ";
}