// https://cses.fi/problemset/task/1092
#include <iostream>
#include <math.h>
#include <vector>
#define ll unsigned long long int
using namespace std;
// 3,4,5,6,7,8,9,10
// 6,10,15,21,28.36,45,55
int main()
{
    ll n, sum;
    cin >> n;
    sum = n * (n + 1) / 2;
    if (sum % 2 == 1 || n < 3)
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<int> v1, v2;
        if (n % 4 == 0)
        {
            for (int i = 0; i < n; i = i + 4)
            {
                v1.push_back(i + 1);
                v1.push_back(i + 4);

                v2.push_back(i + 2);
                v2.push_back(i + 3);
            }
        }
        else
        {
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            for (int i = 3; i < n; i = i + 4)
            {
                v1.push_back(i + 1);
                v1.push_back(i + 4);

                v2.push_back(i + 2);
                v2.push_back(i + 3);
            }
        }
        cout << "YES" << endl;
        cout << v1.size() << endl;
        for (auto i = v1.begin(); i < v1.end(); i++)
            cout << *i << " ";
        cout << endl;
        cout << v2.size() << endl;
        for (auto i = v2.begin(); i < v2.end(); i++)
            cout << *i << " ";
        cout << endl;
    }
    return 0;
}