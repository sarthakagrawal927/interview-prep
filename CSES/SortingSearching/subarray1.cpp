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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x, temp, till = 0, count = 0, b = 0;
    inp(n);
    inp(x);
    vll vec;
    takeinput(vec, n, temp);
    unordered_map<ll, int> map;

    for (int i = 0; i < n; i++)
    {
        till += vec[i]; //finding prefix

        if (till == x) // if prefix is the sum
        {
            count++;
        }

        if (map.find(till - x) != map.end()) // if difference between x and prefix exists in map, we have already found the subarray
        {
            count++;
        }
        map[till] = i;
    }
    cout << count;
    return 0;
}
