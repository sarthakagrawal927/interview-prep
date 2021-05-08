// find smallest difference

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {3,
                     12,
                     1,
                     2,
                     -6,
                     5,
                     -8,
                     6,
                     -3};

    vector<int> b = {9,
                     12,
                     14,
                     22,
                     46,
                     51,
                     48,
                     61,
                     19};

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    int as = a.size(), bs = b.size(), bestdiff = 1e8;

    int i = 0, j = 0;
    int diff = abs(a[i] - b[j]);
    bestdiff = min(diff, bestdiff);

    while (i < as && j < bs)
    {
        int firstNum = a[i], secondNum = b[j];
        if (firstNum < secondNum)
        {
            diff = secondNum - firstNum;
            i++;
        }
        else if (firstNum > secondNum)
        {
            diff = firstNum - secondNum;
            j++;
        }
        else
        {
            bestdiff = 0;
            break;
        }
        bestdiff = min(bestdiff, diff);
    }
    cout << bestdiff;

    return 0;
}