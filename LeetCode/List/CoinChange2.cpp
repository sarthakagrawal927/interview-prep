#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
//dp to be done later

#define ll long long int
#define rep(i, j, n) for (ll i = j; i < n; i++)

void check(vector<ll> a, ll amount)
{
}

int main()
{
    vector<ll> currency;
    ll a, amount;
    cin >> amount;
    while (cin >> a)
    {
        currency.push_back(a);
    }

    check(currency, amount);
    return 0;
}