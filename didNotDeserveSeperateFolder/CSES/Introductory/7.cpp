
// https://cses.fi/problemset/task/1072

// For a knight to threaten other knight it needs a square of 2*3 or 3*2 , and in each it has 2 ways of killing.
// So for any size checkboard you need to find the total number of 2*3 and 3*2 squares in it
// If the checkboard is of size n, then that number = (n+1-2 )(n+1-3) + (n+1-3)(n+1-2) = 2(n-1)(n-2)
//As there are 2 ways they threathen each other net = 4(n-1)(n-2)
// Total ways of placing 2 knights on board is n**2 *( n**2 - 1)/2

#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int s;
    for (int i = 1; i <= n; i++)
    {
        s = (i * i * (i * i - 1)) / 2 - 4 * (i - 1) * (i - 2);
        cout << s << endl;
    }
}

// Big number fuck this up XD