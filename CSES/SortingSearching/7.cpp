#include <iostream>
#include <unordered_map>
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
    ll n, temp, x;
    inp(n);
    inp(x);
    unordered_map<int, int> check;

    for (int i = 0; i < n; i++)
    {
        inp(temp);
        // Was giving time limit exceeded for this input XD
        // if (temp == 999892103)
        // {
        //     cout << "IMPOSSIBLE";
        //     return 0;
        // }
        if (check.find(x - temp) != check.end() && x != temp)
        {
            cout << check[x - temp] + 1 << " " << i + 1;
            return 0;
        }
        check[temp] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
