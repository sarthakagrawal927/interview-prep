//https://cses.fi/problemset/task/1629
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, t1, t2, count = 0, cur_end = 0;
    inp(n);
    vector<pair<int, int>> times;

    for (ll i = 0; i < n; i++)
    {
        inp(t1);
        inp(t2);
        times.emplace_back(make_pair(t2, t1)); // endtime, startime
    }
    sort(times.begin(), times.end()); // sorts by endtime
    for (auto ele : times)
    {
        if (ele.second >= cur_end)
        {
            cur_end = ele.first;
            count++;
        }
    }
    cout << count;
    return 0;
}
