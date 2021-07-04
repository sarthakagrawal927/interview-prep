#include <math.h>
#include <iostream>
#include <string>
using namespace std;
int getsub(string s, string arr[])
{
    if (s.empty())
    {
        arr[0] = "";
        return 1;
    }
    int smallOutput = getsub(s.substr(1), arr);
    for (int i = 0; i < smallOutput; i++)
    {
        arr[smallOutput + i] = arr[i] + s[0];
    }
    return 2 * smallOutput;
}

// creates a tree like structure for every character we decide whether to include it or not
void subsec(string inp, string out)
{
    if (inp.empty()) // hits base case 2^n times
    {
        cout << out << endl;
        return;
    }
    subsec(inp.substr(1), out);
    subsec(inp.substr(1), out + inp[0]);
}

int main(int argc, const char **argv)
{
    string s;
    cin >> s;
    string *arr = new string[(int)(pow(2, s.size()))];
    int n = getsub(s, arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    subsec(s, "");
    return 0;
}