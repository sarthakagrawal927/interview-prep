#include <iostream>

using namespace std;

#define ll long long int

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a7 = 0, a5 = 0, a3 = 0;
        if (n == 4 || n < 3)
        {
            cout << -1 << "\n";
        }
        else
        {
            if (n == 3)
            {
                a3 = 1;
            }
            else if (n == 5)
            {
                a5 = 1;
            }
            else if (n == 6)
            {
                a3 = 2;
            }
            else if (n == 7)
            {
                a7 = 1;
            }
            else
            {
                // let number be 8n + k;
                a3 = n / 8;
                a5 = n / 8;
                n %= 8;
                if (n == 1)
                {
                    a3 += 2;
                    a5 -= 1;
                }
                else if (n == 2)
                {
                    a5 -= 1;
                    a7 = 1;
                }
                else if (n == 3)
                    a3 += 1;
                else if (n == 4)
                {
                    a3 -= 1;
                    a7 = 1;
                }
                else if (n == 5)
                    a5 += 1;
                else if (n == 6)
                    a3 += 2;
                else if (n == 7)
                    a7 = 1;
            }
            cout << a3 << " " << a5 << " " << a7 << "\n";
            // cout << a3 * 3 + a5 * 5 + a7 * 7 << "\n";
        }
    }
    return 0;
}
