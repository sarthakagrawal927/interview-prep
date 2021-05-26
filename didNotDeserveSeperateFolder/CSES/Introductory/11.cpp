// https://cses.fi/problemset/task/1754
#include <iostream>
#include <math.h>
#define ll unsigned long long int
using namespace std;
int main()
{
    ll n, a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if ((a + b) % 3 == 0)
        {
            if (a > b)
            {
                if (a <= 2 * b)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                if (b <= 2 * a)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}