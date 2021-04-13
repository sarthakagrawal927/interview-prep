#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int t, n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    char a;
    while (t--)
    {
        int count = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a == '1')
                count++;
        }

        cout << (count * (count + 1)) / 2 << '\n';
    }
    return 0;
}
