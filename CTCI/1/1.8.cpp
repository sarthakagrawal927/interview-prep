//if an element is 0, make every element in its row & column as 0
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, start, end) for (auto i = start; i < end; i++)
int main()
{
    int n = 10, m = 9;
    int a[10][9] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 0, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 0, 9,
                    1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 0, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 8, 9};
    // rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
    vector<int> rows, columns;

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << a[i][j] << " ";
            if (a[i][j] == 0)
            {
                rows.push_back(i);
                columns.push_back(j);
            }
        }
        cout << endl;
    }
    cout << endl;

    rep(i, rows.begin(), rows.end()) rep(j, 0, m) a[*i][j] = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    rep(i, columns.begin(), columns.end()) rep(j, 0, n) a[j][*i] = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}