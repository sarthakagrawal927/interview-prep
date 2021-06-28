// pattern matching
#include <bits/stdc++.h>
using namespace std;

string getNewPattern(string s)
{
    if (s[0] != 'x')
        for (int i = 0; i < s.size(); i++)
            s[i] = s[i] == 'x' ? 'y' : 'x';
    return s;
}

int countY(string s)
{
    int c = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'y')
            c++;
    return c;
}

int countStartX(string s)
{
    int c = 0, i = 0;
    while (s[i++] == 'x')
        c++;
    return c;
}

bool checkAnswer(string pattern, string x, string y, string out)
{
    string ans = "";
    for (int i = 0; i < pattern.size(); i++)
    {
        if (pattern[i] == 'x')
            ans += x;
        else
            ans += y;
    }
    return ans == out;
}

pair<string, string> getSoln(string s1, string s2)
{
    int n = s2.size();
    s1 = getNewPattern(s1);
    int yc = countY(s1);
    int xc = s1.size() - yc;
    int startX = countStartX(s1);
    int xl = 1;
    string x, y;
    while (true)
    {
        if ((n - xl * xc) % yc)
            continue;
        int yl = (n - xl * xc) / yc;
        if (yl < 1)
            break;
        y = s2.substr(startX * xl, yl);
        x = s2.substr(0, xl);
        xl++;
        if (checkAnswer(s1, x, y, s2))
            break;
    }
    return make_pair(x, y);
}

int main()
{
    string s1 = "xxyxxy";
    string s2 = "gogopowerrangergogopowerranger";
    cout << getSoln(s1, s2).second;
    return 0;
}