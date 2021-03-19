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
        vector<int> arr;
        cin >> n;
        while (n--)
        {
            cin >> temp;
            arr.push_back(temp);
        } // 1 0 4 8 // 5 4 8 8 // 7 6 8 10 // 10 9 10 10 //
    }
    return 0;
}
