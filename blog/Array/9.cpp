
// Sort binary array
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long int
#define vll vector<ll>
#define REP(i, a, b) for (auto i = a; i < b; i++)

using namespace std;

void dutch(vll arr)
{
    int c0 = 0, c1 = 0;
    REP(i, 0, arr.size())
    {
        if (arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
    }
    int c2 = arr.size() - c0 - c1;
    cout << c0 << "0s" << c1 << "1s" << c2 << "2s";
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n;
    vll arr(n);
    REP(i, 0, n)
    cin >> arr[i];
    dutch(arr);
    return 0;
}
