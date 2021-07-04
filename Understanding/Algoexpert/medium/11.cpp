// Kadane

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {3, -12, 1, 2, -6, 5, -8, 6, 3, -3, 6};

    int tot_max = -1e8, curr_max = -1e8;

    for (int i = 0; i < a.size(); i++)
    {
        curr_max = max(curr_max + a[i], a[i]);
        tot_max = max(tot_max, curr_max);
    }
    cout << tot_max;

    return 0;
}
