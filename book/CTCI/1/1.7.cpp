//Matrix_Rotation
#include <iostream>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
int main()
{
    int n = 4;
    int a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int sol[4][4] = {0};
    // rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cout << a[i][j] << " ";
            sol[i][j] = a[n - j - 1][i];
        }
        cout << endl;
    }
    cout << endl;
    rep(i, 0, n)
    {
        rep(j, 0, n) cout << sol[i][j] << " ";
        cout << endl;
    }
    return 0;
}