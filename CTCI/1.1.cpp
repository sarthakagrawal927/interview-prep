
//Unique String - Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures ?
//Better Solution - Using hash table
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
#define reprev(i, start, end) for (int i = start; i > end; i--)

int main()
{
    string s = "";
    getline(cin, s);
    sort(s.begin(), s.end());
    bool ans = true;
    rep(i, 0, s.length() - 1) if (s[i] == s[i + 1])
    {
        ans = false;
    }
    cout << s << "\n"
         << ans;
}