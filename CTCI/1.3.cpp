//URLify: Write a method to replace all spaces in a string with '%20: You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
#define reprev(i, start, end) for (int i = start; i > end; i--)

int main()
{
    string s = "", p = "";
    getline(cin, s);
    int space = 0;

    rep(i, 0, s.length())
    {
        if (s[i] != ' ')
        {
            p += s[i];
            space = 0;
        }
        if (s[i] == ' ' && space == 0)
        {
            p += "%20";
            space = 1;
        }
    }
    cout << p;
}