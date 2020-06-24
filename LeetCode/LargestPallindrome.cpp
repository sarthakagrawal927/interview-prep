#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
//dp to be done later

#define ll long long int
#define rep(i, j, n) for (ll i = j; i > n; i--)

void pallindrome(int n)
{
    int s = n;
    int dup = 0;
    while (s > 0)
    {
        dup = dup * 10 + s % 10;
        s /= 10;
    }
    if (dup == n)
        cout << dup << "\n";
}

int main()
{
    rep(i, 100000, 99000)
    {
        rep(j, 100000, 99000)
        {
            pallindrome(i * j);
        }
    }

    return 0;
}