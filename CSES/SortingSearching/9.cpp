//https://cses.fi/problemset/task/1074/
//Ternary Search
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>
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

ll cost(vll vec, ll chosen)
{
    ll c = 0;
    for (auto i = vec.begin(); i < vec.end(); i++)
        c += abs(chosen - *i);
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, c = 0, ma, mi, mid1, mid2;
    inp(n);
    vll vec;
    takeinput(vec, n);
    ma = *max_element(vec.begin(), vec.end());
    mi = *min_element(vec.begin(), vec.end());

    while ((ma - mi) > 2)
    {
        mid1 = mi + (ma - mi) / 3;
        mid2 = ma - (ma - mi) / 3;

        ll c1 = cost(vec, mid1);
        ll c2 = cost(vec, mid2);

        if (c1 > c2)
        {
            mi = mid1;
        }
        else
        {
            ma = mid2;
        }
    }

    cout << cost(vec, (ma + mi) / 2);

    return 0;
}
