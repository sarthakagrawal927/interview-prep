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
#define pi pair<int, int>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (auto i = a; i <= b; i++)

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
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}