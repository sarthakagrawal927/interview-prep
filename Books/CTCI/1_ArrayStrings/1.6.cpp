//String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.
#include <iostream>
#include <string>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)

int main()
{
    string s = "", p = "";
    getline(cin, s);
    int k = 1;

    rep(i, 0, s.length())
    {
        p = p + s[i];
        while (s[i] == s[i + 1])
        {
            i++;
            k++;
        }
        string t = to_string(k);
        k = 1;
        p += t;
    }
    cout << p;
}