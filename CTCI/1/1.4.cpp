//Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome
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
    sort(s.begin(), s.end());
    int notrepeat = 0, flag = 0;
    rep(i, 0, s.length()) if (s[i] != ' ') //remove space
        p += s[i];
    sort(p.begin(), p.end());
    cout << p << endl;

    rep(i, 0, p.length())
    {
        if (p[i] != p[i + 1])
            notrepeat++;
        else
            i++;
        // cout << i << endl;

        if (notrepeat > 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Not";
    else
        cout << "yes";
}