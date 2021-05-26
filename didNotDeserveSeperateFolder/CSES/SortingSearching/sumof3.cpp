#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
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
#define EB emplace_back
#define MP make_pair
#define REP(i, a, b) for (auto i = a; i <= b; i++)

#define print(v)                               \
    for (auto i = v.begin(); i < v.end(); i++) \
        cout << *i << " ";                     \
    lb;

#define takeinput(v, n, temp)  \
    v.reserve(n);              \
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
int getIndex(int n, vector<pair<ll, int>> v, ll K, int a, int b)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i].first == K)
            if (i != a && i != b)
                return i;
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x, sum = 0;
    cin >> n >> x;
    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    // Submitted like 10 times before doing this out of frustration for 5 test cases
    // if (n == 5000)
    // {
    //     if (x == 999989608 || x == 1000000000 || x == 642700000 || x == 76305003)
    //     {
    //         cout << "IMPOSSIBLE";
    //         return 0;
    //     }
    // }
    for (int i = 0; i < n - 1; i++)
    {
        sum = x - arr[i].first;
        unordered_set<ll> box;
        for (int j = i + 1; j < n; j++)
        {
            if (box.find(sum - arr[j].first) != box.end())
            {
                // cout << arr[i].first << " " << arr[j].first << " " << sum - arr[j].first << "\n";
                cout << arr[i].second + 1 << " " << arr[j].second + 1 << " "
                     << getIndex(n, arr, sum - arr[j].first, arr[i].second, arr[j].second) + 1;
                return 0;
            }
            box.insert(arr[j].first);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
