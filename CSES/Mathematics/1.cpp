// https://cses.fi/problemset/task/1095
//COPIED & CAN BE REPLICATED
#include <iostream>
#include <math.h>
#define ll unsigned long long int
#define MOD 1000000007
using namespace std;
ll power(ll a, ll b)
{
    a = a % MOD;
    ll res = 1;
    while (b)
    {
        if (b & 1) // b%2==1 equivalent but faster
        {
            res = (res * a) % MOD; // if odd then take 1
            // cout << "b&" << endl;
        }

        b >>= 1; // faster b/2
        a = (a * a) % MOD;
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
        ll a, b;
        cin >> a >> b;
        cout << power(a, b) << "\n";
    }
    return 0;
}