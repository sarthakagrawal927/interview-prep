#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t, n, k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<string> dic(n);
        for (int i = 0; i < n; i++)
            cin >> dic[i];
        vector<string> mod;
        string temp;

        for (int i = 0; i < k; i++)
        {
            int l;
            cin >> l;
            for (int i = 0; i < l; i++)
            {
                cin >> temp;
                mod.push_back(temp);
            }
        }
        int si = mod.size(), yes = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < si; j++)
            {
                if (dic[i] == mod[j] && !yes)
                {
                    cout << "YES ";
                    yes = 1;
                }
            }
            if (yes == 0)
                cout << "NO ";
            yes = 0;
        }
        cout << "\n";
    }
    return 0;
}
