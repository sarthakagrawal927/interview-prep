// sub array sort -min range of element to sort to completely sort the array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 4, 7, 10, 11, 6, 7, 12, 7, 16, 18, 19};

    int n = a.size();
    int first, last = 0;
    for (int i = 0; i < n; i++) // finding first and last issue
    {
        if (i == 0)
        {
            if (a[i] > a[i + 1])
                first = i;
        }

        else if (i == n - 1)
        {
            if (a[i] < a[i - 1])
                last = i;
        }

        else if (a[i] > a[i + 1] || a[i - 1] > a[i])
        {
            last = max(last, i);
            first = min(first, i);
        }
    }

    int minE = 1e8, maxE = -1e8;

    for (int i = first; i <= last; i++) // finding minimum and maximum issue
    {
        minE = min(minE, a[i]);
        maxE = max(maxE, a[i]);
    }

    int f = 0, l = n - 1; // finding position for errors

    while (minE > a[f])
        f++;

    while (maxE < a[l])
        l--;

    cout << first << " " << last << endl;
    cout << minE << " " << maxE << endl;
    cout << f << " " << l << endl;

    return 0;
}