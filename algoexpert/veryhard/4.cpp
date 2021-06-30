// String Matching - Knuth-Morris-Pratt Algo
#include <bits/stdc++.h>
using namespace std;

bool kmp(string sen, string pat)
{
    int n = sen.size(), m = pat.size();
    return n & m;
}

int main()
{
    string s = "aefaefaefaedaefaedaefaefa";
    string t = "aefaedaefaefa";
    cout << kmp(s, t);
    return 1;
}
