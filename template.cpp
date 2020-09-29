#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define MOD 1e9 + 7
#define MAX_INT 1e9
#define MIN_INT -1e9
#define ll long long int
#define vi vector<int>
#define vll vector<ll>

#define print(v)                               \
    for (auto i = v.begin(); i < v.end(); i++) \
        cout << *i << " ";                     \
    cout << endl;

#define takeinput(v, n, temp)  \
    for (ll i = 0; i < n; i++) \
    {                          \
        inp(temp);             \
        v.push_back(temp);     \
    }

#define lb cout << endl
//https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
void inp(ll &number)
{
    bool negative = false;
    register int c;

    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, b, c;
    inp(n);
    inp(b);
    inp(c);
    cout << n << b << c;
    return 0;
}
