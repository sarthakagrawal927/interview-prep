// Disk Stacking
// Stack disk such that every disk has the smaller dimension compared to disks above it.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // array of disks, having length, breath, height, maxHeight
    vector<vector<int>> ans = {{2, 2, 1, 1}, {2, 1, 2, 2}, {3, 2, 3, 3}, {2, 3, 4, 4}, {4, 4, 5, 5}, {2, 2, 8, 8}};
    int n = ans.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (ans[i][0] > ans[j][0] && ans[i][1] > ans[j][1] && ans[i][2] > ans[j][2])
                ans[i][3] = max(ans[i][3], ans[j][3] + ans[i][2]);
            cout << ans[i][3] << " ";
        }
    }
    cout << ans[n - 1][3];
    return 0;
}