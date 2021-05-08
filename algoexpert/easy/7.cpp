// binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {1,
                       2,
                       4,
                       232,
                       42,
                       23,
                       4,
                       3,
                       321};
    sort(arr.begin(), arr.end());
    int tar = 1;

    int start = 0, end = arr.size();

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == tar)
        {
            cout << " found";
            break;
        }
        else if (arr[mid] > tar)
        {
            end = mid;
        }
        else
            start = mid;
    }

    return 0;
}