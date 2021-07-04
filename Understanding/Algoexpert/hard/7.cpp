// Minumum no. of jumps to go from start to end
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {3, 4, 2, 1, 2, 3, 2, 1, 1, 1, 3};
    int n = a.size();

    vector<int> jumps(n, 1e8); // jumps needed to i index
    jumps[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] + j >= i)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << jumps[i] << " ";
    }

    return 0;
}
