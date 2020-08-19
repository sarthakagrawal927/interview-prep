//https://www.codechef.com/LRNDSA02/problems/PSHOT
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)

int main()
{
    int t;
    cin >> t;
    vector<int> victory;
    rep(j, 0, t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> win;
        int a = 0, b = 0, someoneWon = 0;
        rep(i, 0, 2 * n)
        {
            if (s[i] == '1')
            {
                if (i % 2 == 0)
                    a++;
                else
                    b++;
            }
            if ((a > (n - i / 2 - i % 2 + b)) || b > (n - i / 2 - i % 2 - 1 + a))
            {
                victory.push_back(i + 1);
                // cout << a << " " << b << endl;
                someoneWon = 1;
                break;
            }
        }
        // cout << a << " " << b << endl;
        if (someoneWon == 0)
            victory.push_back(2 * n);
    }
    rep(j, 0, t) cout << victory[j] << endl;
}