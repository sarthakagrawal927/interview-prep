//https://www.quora.com/How-can-we-calculate-a-b-c-mod-n
// https://cses.fi/problemset/task/1712

#include <iostream>
#include <math.h>
#define ll unsigned long long int
#define MOD 1000000007
using namespace std;
ll power(ll a, ll b, ll m)
{
    a = a % m;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        b >>= 1; // faster b/2
        a = (a * a) % m;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0); //faster input output
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll d = power(b, c, MOD - 1);
        cout << power(a, d, MOD) << "\n";
    }
    return 0;
}