#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define ll long long int
#define vll vector<ll>

#define takeinput(v, n, temp)  \
    for (ll i = 0; i < n; i++) \
    {                          \
        cin >> temp;           \
        v.emplace_back(temp);  \
    }

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, temp;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vll v;
        takeinput(v, n, temp);
        sort(v.begin(), v.end());
        cout << accumulate((v.begin() + n - 1 - k), v.end(), 0) << "\n";
    }
    return 0;
}
