// Max subset sum no adjacent
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {3,
                     -12,
                     1,
                     2,
                     -6,
                     5,
                     -8,
                     6,
                     3};

    int n = a.size();
    a[0] = a[0];
    a[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++)
    {
        a[i] = max(a[i - 1], a[i - 2] + a[i]);
    }
    cout << a[n - 1];
    return 0;
}

/*
   vector<int> maxsums(n);
    maxsums[0] = a[0];
    maxsums[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++)
    {
        maxsums[i] = max(maxsums[i - 1], maxsums[i - 2] + a[i]);
    }
    cout << maxsums[n - 1];
*/