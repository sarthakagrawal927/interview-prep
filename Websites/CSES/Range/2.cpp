// https://cses.fi/problemset/task/1647
// Segment tree to be done later

#include <iostream>
#include <vector>
#include <numeric>
#define ll long long int
using namespace std;
int main()
{
    int n, q;
    ll x, a, b, min = -1e9;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    vector<ll> v;
    while (n--)
    {
        cin >> x;
        if (min < x)
            min = x;
        v.push_back(min);
    }
    while (q--)
    {
        cin >> a >> b;
        }
    return 0;
}