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
#define lb cout << "\n"

#define print(v)                               \
    for (auto i = v.begin(); i < v.end(); i++) \
        cout << *i << " ";                     \
    lb;

#define takeinput(v, n)        \
    ll temp;                   \
    for (ll i = 0; i < n; i++) \
    {                          \
        inp(temp);             \
        v.emplace_back(temp);  \
    }

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
    ll n, temp, max1 = MIN_INT, cur = 0;
    inp(n);
    vll vec;
    // Kadane's algorithm
    for (int i = 0; i < n; i++)
    {
        inp(temp);
        cur += temp;
        if (cur > max1)
            max1 = cur;
        if (cur < 0)
            cur = 0;
    }
    cout << max1;
    return 0;
}
