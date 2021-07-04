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
        cin >> n;
        int temp2 = n, sum = 0, mi = 1e8;
        while (temp2--)
        {
            cin >> temp;
            sum += temp;
            if (mi > temp)
                mi = temp;
        }                             // 1 0 4 8 // 5 4 8 8 // 7 6 8 10 // 10 9 10 10 //
        cout << sum - n * mi << endl; // or decrease everyone to the smallest
    }
    return 0;
}
