// https://cses.fi/problemset/task/1090
#include <iostream>
#include <vector>
#include <algorithm>
#define ll unsigned long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> v;
    while (n--)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    ll count = 0;
    auto i = v.begin();
    auto j = v.end() - 1;
    while (i <= j)
    {
        if ((*j + *i) <= x)
        {
            j--;
            i++;
        }
        else
            j--;
        count++;
    }
    cout << count;
    return 0;
}