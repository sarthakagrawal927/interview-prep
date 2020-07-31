//https://www.codechef.com/LRNDSA02/problems/STFOOD
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)

int main()
{
    int t;
    cin >> t;
    vector<int> maxArray;
    rep(j, 0, t)
    {
        int n;
        cin >> n;
        int p, s, v;
        vector<int> worth;
        rep(i, 0, n)
        {
            cin >> s;
            cin >> p;
            cin >> v;
            worth.push_back((p / (++s)) * v);
        }
        maxArray.push_back(*max_element(worth.begin(), worth.end()));
    }
    rep(j, 0, t) cout << maxArray[j] << endl;
}