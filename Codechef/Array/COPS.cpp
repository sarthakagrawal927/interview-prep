#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t, n, temp;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        vector<int> h(100, 0);
        int x, y, M, range;
        cin >> M >> x >> y;
        range = x * y;
        while (M--)
        {
            cin >> temp;
            temp -= 1;
            int start = temp - range, end = temp + range;
            start = start >= 0 ? start : 0;
            end = end < 100 ? end : 99;
            for (int i = start; i <= end; i++)
                h[i] = 1;
        }
        int count = 0;
        for (int i = 0; i < 100; i++)
            count += h[i];
        cout << 100 - count << '\n';
    }
    return 0;
}
