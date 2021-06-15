#include <iostream>
using namespace std;

bool isOdd(int n)
{
    return n & 1;
}
int main()
{
    int n, result = 0;
    cin >> n;
    cout << isOdd(n) << endl;
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

    cout << n << endl;

    while (n)
    {
        result ^= (n & 1);
        n >>= 1;
    }
    cout << result;

    return 0;
}