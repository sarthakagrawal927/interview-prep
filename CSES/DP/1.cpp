#include <iostream>

using namespace std;
#define MOD 1e9 + 7
#define MAX_INT 1e9
#define MIN_INT -1e9
#define ll long long int
#define vi vector<int>
#define vll vector<ll>

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n = 0;
    cin >> n;

    ll a[1000000];
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 8;
    a[5] = 16;
    a[6] = 32;
    if (n <= 6)
    {
        cout << a[n];
        return 0;
    }
    for (int i = 7; i <= n; i++)
        a[i] = ((2 * a[i - 1] % (ll)(MOD)) % (ll)(MOD)-a[i - 7] % (ll)(MOD)) % (ll)(MOD);

    cout << a[n];
    return 0;
}
