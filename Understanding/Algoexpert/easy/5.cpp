// nth fibo

#include <iostream>
using namespace std;

int main()
{
    int n = 10, a = 0, b = 1, c = 0;
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        cout << c << " ";
    }
    return 0;
}