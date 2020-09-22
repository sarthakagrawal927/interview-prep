//https://www.codechef.com/LRNDSA02/problems/PSHOT
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        string goals;
        cin >> n >> goals;
        int i, earliest = -1, aPoints = 0, bPoints = 0, aLeft = n, bLeft = n;
        for (i = 0; i < 2 * n; ++i)
        {
            if (goals[i] == '1')
                (i % 2 ? ++bPoints : ++aPoints);
            (i % 2 ? --bLeft : --aLeft);
            if (bPoints > aPoints + aLeft || aPoints > bPoints + bLeft)
            {
                earliest = i + 1;
                break;
            }
        }
        if (earliest == -1 || (aPoints == bPoints && i == n))
        {
            earliest = 2 * n;
        }
        cout << earliest << "\n";
    }
}