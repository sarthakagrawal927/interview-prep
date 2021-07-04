// max sum increasing subsequence

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {8, 12, 2, 3, 15, 5, 7, 2, 43, 21, 32};
    int n = a.size(), start, reqInd = -1, bestOption = 0, maxIndex = -1, maxVal = -1;
    vector<int> seq(n, -1), sum(n, 0);
    sum[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        start = 0;
        while (start < i)
        {
            if (a[i] > a[start++] && bestOption < sum[start - 1])
            {
                reqInd = start - 1;
                bestOption = sum[reqInd];
            }
        }

        // Finding next element
        if (reqInd != -1)
            sum[i] = a[i] + sum[reqInd];
        else
            sum[i] = a[i];

        if (maxVal < sum[i]) // saving max
        {
            maxIndex = i;
            maxVal = sum[i];
        }

        //  storing sequence
        seq[i] = reqInd;

        // resetting variables
        reqInd = -1;
        bestOption = 0;
    }

    cout << maxVal << endl;
    while (maxIndex != -1)
    {
        cout << a[maxIndex] << " ";
        maxIndex = seq[maxIndex];
    }

    return 0;
}