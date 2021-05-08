// Pallindrome

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool pallindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    string arr = "sarttsras";
    int n = arr.size();

    cout << pallindrome(arr);

    return 0;
}