// Search in sorted Matrix

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Space and Time complexity : n2^n - iterative
int main()
{

    vector<vector<int>> arr = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                               {32, 33, 39, 50}};
    int target = 29;

    int i = 0, j = arr[0].size() - 1;
    while (i < arr.size() && j >= 0)
    {
        cout << arr[i][j] << " ";
        if (arr[i][j] == target)
        {
            cout << "\n"
                 << i << j;
            break;
        }
        else if (arr[i][j] < target)
            i++;
        else
            j--;
    }

    return 0;
}
