// https://cses.fi/problemset/task/1094
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int num, next;
    cin >> num;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    n -= 1;
    long long int count = 0;

    while (n > 0)
    {
        cin >> next;
        n--;
        if (num > next)
        {
            count += (num - next);
            next = num;
        }
        num = next;
    }
    cout << count;

    return 0;
}