#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t, n, temp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        long long int c, sum = 0;
        cin >> n >> c;
        while (n--)
        {
            cin >> temp;
            sum += temp;
        }
        if (sum <= c)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
