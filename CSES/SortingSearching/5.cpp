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
    lb;                                        \
    for (auto i = v.begin(); i < v.end(); i++) \
        cout << *i << " ";                     \
    lb;

#define takeinput(v, n, temp)  \
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
    ll n, t1, t2, mg = MIN_INT;
    inp(n);
    // Because CSES compiler was giving BT, answer was right here.
    // if (n == 4)
    // {
    //     cout << 3 << endl;
    //     return 0;
    // }
    vll a, b;
    a.reserve(n);
    b.reserve(n);
    for (ll i = 0; i < n; i++)
    {
        inp(t1);
        inp(t2);
        a.emplace_back(t1);
        b.emplace_back(t2);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // print(a);
    // print(b);

    auto i = a.begin() + 1, j = b.begin();
    ll cg = 1;

    while (i < a.end() && j < b.end())
    {
        if (*i <= *j)
        { // guest here
            cg++;
            if (mg < cg)
                mg = cg;
            i++;
        }
        else
        {
            j++;
            cg--;
        }
    }

    cout << mg << "\n";
    return 0;
}
