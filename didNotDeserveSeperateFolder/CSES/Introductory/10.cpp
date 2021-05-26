// https://cses.fi/problemset/task/1618
#include <iostream>
#include <math.h>
#define ll unsigned long long int
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll number = 0;
    int i = 1;
    while (pow(5, i) <= n)
    {
        number += n / pow(5, i);
        i++;
    }
    cout << number;
    return 0;
}