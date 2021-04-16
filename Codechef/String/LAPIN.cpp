#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool checkEqual(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main(int argc, char const *argv[])
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        string s, s1, s2;
        cin >> s;
        int l = s.size();
        if (l % 2)
        {
            s1 = s.substr(0, l / 2);
            s2 = s.substr(l / 2 + 1, l - 1);
        }
        else
        {
            s1 = s.substr(0, l / 2);
            s2 = s.substr(l / 2, l - 1);
        }
        cout << (checkEqual(s1, s2) ? "YES" : "NO") << endl;
    }
    return 0;
}
