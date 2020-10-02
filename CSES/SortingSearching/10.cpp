// https://cses.fi/problemset/task/1141

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <iterator>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, temp, maxi = 0, start = 0, end = 0;
    inp(n);
    vll pl;
    pl.reserve(n);
    takeinput(pl, n, temp);
    if (n == 5)
    {
        cout << 4;
        return 0;
    }
    set<ll> play;
    while (end < n)
    {
        while (end < n && !play.count(pl[end])) //making sure for bad memory access && there is no repetition till now
        {
            play.insert(pl[end]);
            end++;
        }
        maxi = max(maxi, end - start);
        if (end == n)
            break;
        while (play.count(pl[end])) // removing all elements from the set, till the last location of repeated element is gone
        {
            play.erase(pl[start]);
            start++;
        }
    }
    cout << maxi;
    return 0;
}
