#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <unordered_map>
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

#define takeinput(v, n, temp)  \
    for (ll i = 0; i < n; i++) \
    {                          \
        inp(temp);             \
        v.emplace_back(temp);  \
    }

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
ll findcount(vll vec, ll n, ll sum)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else if (n <= 0 && n >= 1)
        return 0;

    return findcount(vec, n - 1, sum) + findcount(vec, n, sum - vec[n - 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, temp, sum;
    inp(n);
    inp(sum);
    vll vec;
    takeinput(vec, n, temp);
    cout << findcount(vec, n, sum);
    return 0;
}
