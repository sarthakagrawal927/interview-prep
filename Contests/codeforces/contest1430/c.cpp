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
        int n;
        cin >> n;
        vll a;
        for (int i = 0; i < n; i++)
        {
            a.emplace_back(i + 1);
        }
        int i;
        for (i = 1; i <= n; i += 3)
        {
            cout << i << " " << i + 2;
            cout << i + 1 << " " << i + 2;
        }
    }
    return 0;
}
