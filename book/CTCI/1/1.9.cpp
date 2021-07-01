//isRotationOf function
#include <iostream>
#include <string>
using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)

bool isRotationOf(string s, string p)
{
    int i = s.length() - 1;
    int len = s.length();
    string w1 = "", w2 = "";
    while (w1.length() < len)
    {
        w1 += s[i];
        w2 = s[i--] + w2;
        // cout << "w=" << w << endl;
        // cout << "s=" << s << endl;
        s.pop_back();
        string s1 = w1 + s;
        string s2 = w2 + s;
        if ((s1.compare(p) == 0) || (s2.compare(p) == 0))
            return true;
        // cout << w1 + s << endl;
        // cout << w2 + s << endl;
    }
    return false;
}
int main()
{
    string s, p;
    getline(cin, s);
    getline(cin, p); //assuming length is same
    cout << isRotationOf(s, p);
}