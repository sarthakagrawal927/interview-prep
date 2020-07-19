//One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character.Given two strings, write a function to check if they are one edit(or zero edits) away.
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
    getline(cin, p); //assuming s > p and only by 1  char.

    int loop = s.length() < p.length() ? s.length() : p.length();
    int diffLeft = 0, diffRight = 0;
    if (s.length() == p.length())
    {
        rep(i, 0, loop)
        {
            if (s[i] != p[i])
                diffLeft++;

            if (s[loop - i] != p[loop - i])
                diffRight++;
        }
        if (diffLeft == diffRight && diffLeft == 1)
            cout << "yes";
        else
            cout << "no";
    }
    else // s > p by 1 char
    {
        rep(i, 0, loop)
        {
            if (s[i] != p[i])
                diffLeft++;

            if (s[loop - i] != p[loop - i - 1]) //as s is exactly 1 character bigger
                diffRight++;
        }
        if ((diffLeft + diffRight) == loop)
            cout << "yes";
        else
            cout << "no";
    }
    // cout << diffLeft << " " << diffRight << endl;
}