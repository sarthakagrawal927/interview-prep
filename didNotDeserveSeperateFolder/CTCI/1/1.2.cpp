//Check Permutation: Given two strings, write a method to decide if one is a permutation of the other
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

    if (s == p)
        cout << "true";
    else
        cout << "false";
}