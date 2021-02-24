#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <unordered_map>
#include <algorithm>
using namespace std;

// class Pizza(){
//     vector<string> ingredients;
//     int index,
// }

int main()
{
    int M, T2, T3, T4, team_delivered = 0;

    map<set<string>, vector<int>> pizza;
    vector<bool> vis(M, 0);
    vector<vector<int>> ans(5);

    cin >> M >> T2 >> T3 >> T4;

    int Mcpy = M;
    while (Mcpy--)
    {
        int I;
        cin >> I;
        set<string> s;
        for (int i = 0; i < I; ++i)
        {
            string ch;
            cin >> ch;
            s.insert(ch);
        }
        pizza[s].push_back(M - Mcpy - 1);
    }

    while (M > 1 && (T2 || T3 || T4))
    {
        ++team_delivered;
        if (M >= 4 && T4)
        {
            for (int i = 0, cnt = 4; i < vis.size() && cnt; ++i)
            {
                if (!vis[i])
                {
                    --cnt;
                    ans[4].push_back(i);
                    vis[i] = 1;
                }
            }
            M -= 4;
            T4--;
        }
        else if (M >= 3 && T3)
        {
            for (int i = 0, cnt = 3; i < vis.size() && cnt; ++i)
            {
                if (!vis[i])
                {
                    --cnt;
                    ans[3].push_back(i);
                    vis[i] = 1;
                }
            }
            M -= 3;
            T3--;
        }
        else if (M >= 2 && T2)
        {
            for (int i = 0, cnt = 2; i < vis.size() && cnt; ++i)
            {
                if (!vis[i])
                {
                    --cnt;
                    ans[2].push_back(i);
                    vis[i] = 1;
                }
            }
            M -= 2;
            T2--;
        }
    }

    // output
    cout << team_delivered << endl;
    for (int i = 2; i < 5; ++i)
    {
        for (int j = 0; j < ans[i].size(); j += i)
        {
            if (i == 2)
            {
                cout << i << " " << ans[i][j] << " " << ans[i][j + 1] << endl;
            }
            else if (i == 3)
            {
                cout << i << " " << ans[i][j] << " " << ans[i][j + 1] << " " << ans[i][j + 2] << endl;
            }
            else if (i == 4)
            {
                cout << i << " " << ans[i][j] << " " << ans[i][j + 1] << " " << ans[i][j + 2] << " " << ans[i][j + 3] << endl;
            }
        }
    }
    return 0;
}
