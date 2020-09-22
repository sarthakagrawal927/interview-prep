// https://www.codechef.com/LRNDSA02/problems/STUPMACH

#include <iostream>
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //These 2 lines allow fast input output
    ll t, n, sum = 0, min = 1e18, no;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> no;
            if (no < min)
                min = no;
            sum += min;
        }
        cout << sum << endl;
    }
    return 0;
}