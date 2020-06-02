#include <iostream>
using namespace std;

#define ll long long int
#define rep(i, j, n) for (ll i = j; i < n; i++)

void check(ll a[], int start, int end)
{
    int l = start + (end - start) / 2;

    if (a[l] == a[l + 1])
        check(a, start, l);
    else if (a[l] == a[l - 1])
        check(a, l + 1, end);
    else
        cout << a[l];
}
int main()
{
    ll array[7];

    rep(i, 0, 7) cin >> array[i];

    check(array, 0, 7);
    return 0;
}