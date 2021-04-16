//Dutch Flag
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
#define reprev(i, start, end) for (int i = start; i > end; i--)

int main()
{
    int a[10] = {0};
    rep(i, 0, 10) cin >> a[i];
    int red1 = 0, green3 = 9, temp = 0, blue2 = 0;
    rep(i, 0, 10)
    {
        if (a[i] < 2)
        {
            a[i] = a[red1];
            a[red1] = 1;
            red1++;
        }
    }
    // rep(i, 0, 10) cout << a[i] << " ";
    reprev(i, 9, red1 - 1)
    {
        if (a[i] > 2)
        {
            a[i] = a[green3];
            a[green3] = 3;
            green3--;
        }
    }

    rep(i, 0, 10) cout << a[i] << " ";
}