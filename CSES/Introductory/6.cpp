// https://cses.fi/problemset/task/1071
#include <iostream>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin >> n;
    ll x, y, number;
    while (n--)
    {
        cin >> y >> x;
        x -= 1;
        y -= 1;
        if (x >= y)
        {
            if (x % 2 == 0)
            {
                number = (x + 1) * (x + 1) - y;
            }
            else
            {
                number = x * x + y + 1;
            }
        }
        else
        {
            if (y % 2 == 0)
            {
                number = y * y + 1 + x;
            }
            else
            {
                number = (y + 1) * (y + 1) - x;
            }
        }
        cout << number << endl;
    }

    return 0;
}