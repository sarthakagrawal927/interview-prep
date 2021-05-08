// Caesor Cipher Encryptor
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string shift(string s, int shiftBy)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if ((int)s[i] - shiftBy < 97)
            s[i] = (char)((int)s[i] - shiftBy + 26);

        else
            s[i] = (char)((int)s[i] - shiftBy);
    }
    return s;
}

int main()
{
    string arr = "defghijk";
    int n = arr.size();
    int shiftBy = 4;
    cout << shift(arr, shiftBy % 26);
    return 0;
}