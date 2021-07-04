// https://cses.fi/problemset/task/1083

#include <iostream>
using namespace std;
int main()
{
    long long int n, s = 0, d = 0;
    cin >> n;
    long long int sum = (n * (n + 1)) / 2;
    while (n != 1)
    {
        n--;
        cin >> d;
        s += d;
    }
    cout << sum - s;
    return 0;
}