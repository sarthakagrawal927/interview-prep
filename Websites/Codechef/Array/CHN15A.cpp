#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 0, count = 0;
        cin >> n >> k;
        while (n--)
        {
            int temp = 0;
            cin >> temp;
            temp += k;
            if (temp % 7 == 0)
                count++;
        }
        cout << count << '\n';
    }
    return 0;
}
