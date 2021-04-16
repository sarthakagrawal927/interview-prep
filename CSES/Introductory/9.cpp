// https://cses.fi/problemset/task/1618
#include <iostream>
#include <math.h>
#define ll unsigned long long int
using namespace std;
int main()
{
    ll n;
    cin >> n;
    int mod = n % 63;
    ll div = n / 63, k = 1;
    ll x = pow(2, 63);
    x %= 1000000007;

    ll y = pow(2, mod);
    y %= 1000000007;
    while (div > 0)
    {
        k = (k % 1000000007) * x;
        k %= 1000000007;
        div--;
    }
    k *= y;
    k %= 1000000007;
    cout << k;
    return 0;
}