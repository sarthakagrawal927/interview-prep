// 3 number sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {3,
                       12,
                       1,
                       2,
                       -6,
                       5,
                       -8,
                       6,
                       -3};
    int n = arr.size();
    int target = 0, curr_num;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        curr_num = arr[i]; // keeping 1 number fixed, we move left and right pointers while checking sum
        while (l < r)
        {
            if (arr[l] + arr[r] + curr_num == target)
            {
                cout << arr[l] << " " << arr[r] << " " << curr_num << endl;
                l++;
                r--;
            }
            else if (arr[l] + arr[r] + curr_num < target)
                l++;
            else
                r--;
        }
    }
    return 0;
}