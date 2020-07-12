//Program to add 2 binary numbers
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, start, end) for (auto i = start; i < end; i++)
#define reprev(i, start, end) for (int i = start; i >= end; i--)

int main()
{
    string s = "", t = "";
    cin >> s >> t;
    cout << s << " " << t << endl;

    int max = (s.length() > t.length()) ? s.length() : t.length();

    int ans[100] = {0};

    reprev(i, max, 0)
    {
        int a = (int)s[max - i - 1] - 48;
        int b = (int)t[max - i - 1] - 48;
        if (a != 1)
            a = 0;
        if (b != 1)
            b = 0;
        cout << a + b << " ";

        int s = a + b + ans[i];

        if (s >= 2)
        {
            ans[i] = s - 2;
            ans[i - 1] += 1;
        }
        else
            ans[i] = s;
    }
    cout << endl;
    reprev(i, max, 0) cout << ans[i] << " ";
}