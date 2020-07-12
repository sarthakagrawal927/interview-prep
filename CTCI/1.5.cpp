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
    getline(cin, p);

    sort(s.begin(), s.end());
    sort(p.begin(), p.end());

    int loop = s.length() < p.length() ? s.length() : p.length();
    int diff = s.length() - p.length();

    rep(i, 0, loop)
    {
        if (s[i] != p[i])
            diff++;
    }
}