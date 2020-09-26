// https://cses.fi/problemset/task/1646

#include <iostream>
#include <vector>
#include <numeric>
#define ll long long int
using namespace std;
int main()
{
    int n, q;
    ll x, a, b;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    vector<int> v;
    while (n--)
    {
        cin >> x;
        v.push_back(x);
    }
    while (q--)
    {
        cin >> a >> b;
        cout << accumulate(v.begin() + a - 1, v.begin() + b, 0) << endl;
    }
    return 0;
}