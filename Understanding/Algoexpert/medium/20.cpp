// Bracket Matcher

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

bool isOpening(char c)
{
    return c == '[' || c == '{' || c == '(';
}

bool isMatch(char open, char close)
{
    if (open == '{')
        return close == '}';
    if (open == '(')
        return close == ')';
    else
        return close == ']';
}

bool checkbracket(string s)
{
    stack<char> s1;
    if (!isOpening(s[0]))
        return false;
    s1.push(s[0]);
    int i = 1;
    char t, c;
    while (s1.size() && i < s.size())
    {
        c = s[i++];
        if (!isOpening(c))
        {
            t = s1.top();
            s1.pop();
            if (isMatch(t, c) == false)
                return false;
        }
        else
            s1.push(c);
    }
    return s1.size() == 0;
}
int main()
{
    string s1 = "[[]{({)}]";
    cout << checkbracket(s1);

    return 0;
}