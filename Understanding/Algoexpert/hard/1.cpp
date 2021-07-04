// 4 number sum

#include <bits/stdc++.h>
using namespace std;

// We divide 4 into 2 pairs, and try to implement 2 sum logic
int main()
{
    vector<int> arr = {7, 6, 4, -1, 1, 2, 3, 8};
    int target = 16, curr_sum, diff;
    unordered_map<int, vector<pair<int, int>>> set;
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            curr_sum = arr[i] + arr[j];
            diff = target - curr_sum;
            if (set.find(diff) != set.end())
            {
                for (auto k = set[diff].begin(); k < set[diff].end(); k++)
                {
                    vector<int> a1;
                    a1.push_back(arr[i]), a1.push_back(arr[j]);
                    a1.push_back((*k).first), a1.push_back((*k).second);
                    ans.push_back(a1);
                }
            }
        }

        for (int k = 0; k < i; k++)
        {
            curr_sum = arr[i] + arr[k];
            if (set.find(curr_sum) != set.end())
            {
                set[curr_sum].push_back(make_pair(arr[k], arr[i]));
            }
            else
            {
                vector<pair<int, int>> a2;
                a2.push_back(make_pair(arr[k], arr[i]));
                set[curr_sum] = a2;
            }
        }
    }

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " + ";
        cout << " = " << target << endl;
    }

    return 0;
}