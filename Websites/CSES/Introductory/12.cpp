// https://cses.fi/problemset/task/1754
#include <iostream>
#include <math.h>
#include <string>
#include <numeric>
#define ll unsigned long long int
using namespace std;

int main()
{
    string n;
    getline(cin, n);
    int arr[26] = {0};
    for (int i = 0; i < n.length(); i++)
    {
        arr[(int)n[i] - 65]++;
    }
    int oddChar = -1;
    for (int i = 0; i < 26; i++)
    {
        // cout << (char)(i + 'A') << " = " << arr[i] << endl;
        if (arr[i] % 2 == 1)
        {
            if (oddChar != -1)
            {
                cout << "NO SOLUTION";
                return 0;
            }
            oddChar = i;
        }
    }
    int loc = 0, loc2 = 1;
    for (int i = 0; i < 26; i++)
    {
        // cout << i << endl;
        if (oddChar == i)
        {
            n[n.length() / 2] = (char)(i + 'A');
            arr[i]--;
            while (arr[i] > 0)
            {
                n[n.length() / 2 + loc2] = (char)(i + 'A');
                n[n.length() / 2 - loc2] = (char)(i + 'A');
                arr[i] -= 2;
                // cout << n << endl;
                loc2++;
            }
        }
        else
            while (arr[i] > 0)
            {
                n[loc] = (char)(i + 'A');
                n[n.length() - 1 - loc] = (char)(i + 'A');
                arr[i] -= 2;
                // cout << n << endl;
                loc++;
            }
    }
    cout << n;

    return 0;
}