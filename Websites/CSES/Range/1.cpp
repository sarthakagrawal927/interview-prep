// https://cses.fi/problemset/task/1646

#include <iostream>
#include <vector>
#include <numeric>
#define ll long long int
using namespace std;
int main()
{
    int n, q;
    ll x, a, b, sum = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    vector<ll> v;
    while (n--)
    {
        cin >> x;
        sum += x;
        v.push_back(sum);
    }
    while (q--)
    {
        cin >> a >> b;
        a--;
        b--;
        if (a == 0)
            cout << *(v.begin() + b) << endl;
        else
            cout << *(v.begin() + b) - *(v.begin() + a - 1) << endl;
    }
    return 0;
}