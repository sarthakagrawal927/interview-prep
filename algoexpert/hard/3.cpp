// largest range , like 1,2,3,4,5,6,7

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> a = {1, 11, 3, 0, 15, 5, 2, 4, 10, 12, 6, 8, 9, 16};
    int n = a.size(), maxi = 0, curr = 0, maximum = -1;
    unordered_map<int, bool> s;

    for (int i = 0; i < n; i++) // inserting all numbers with not visited as true and finding max range
    {
        s[a[i]] = true;
        maximum = max(maximum, a[i]);
    }

    cout << maximum << endl;
    for (int i = 0; i < n; i++)
    {
        if (s[a[i]]) // not visited is true
        {
            s[a[i]] = false;
            curr = 0;
            int start = a[i];
            while (start < maximum && s.find(start) != s.end())
            {
                start++;
                curr++;
            }
            maxi = max(maxi, curr);
        }
    }
    cout << maxi;

    return 0;
}