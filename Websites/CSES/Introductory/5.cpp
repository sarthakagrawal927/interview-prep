// https://cses.fi/problemset/task/1070
#include <iostream>
#define ll long long int;
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 1 << endl;
    else if (n < 4)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3" << endl;
    }
    else
    {
        int temp = n;
        while (temp >= 1)
        {
            cout << temp << " ";
            temp -= 2;
        }
        temp = n - 1;
        while (temp >= 1)
        {
            cout << temp << " ";
            temp -= 2;
        }
    }

    return 0;
}