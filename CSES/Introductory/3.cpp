// https://cses.fi/problemset/task/1069/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string x;
    cin >> x;
    int m = x.length(), max1 = 0, count = 0;
    for (int i = 0; i < m;)
    {
        char c = x[i];
        while (c == x[i])
        {
            count++;
            i++;
        }
        if (max1 < count)
            max1 = count;
        count = 0;
    }
    cout << max1;

    return 0;
}

// i: 1
// x[i]: c
// c: c
// op: a