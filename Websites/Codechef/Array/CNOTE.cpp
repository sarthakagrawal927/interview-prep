#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k, n, pageNeed;
        cin >> x >> y >> k >> n;
        pageNeed = x - y;
        bool hap = 0;
        while (n--)
        {
            int p, c;
            cin >> p >> c;
            if (p >= pageNeed && k >= c)
                hap = 1;
        }
        hap == 1 ? cout << "LuckyChef\n" : cout << "UnluckyChef\n";
    }
    return 0;
}
