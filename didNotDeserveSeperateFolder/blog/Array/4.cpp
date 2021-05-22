
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

int count0(vll arr)
{
    int c = 0;
    REP(i, 0, arr.size())
    if (!arr[i])
        c++;
    return c;
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n;
    vll arr(n);
    REP(i, 0, n)
    cin >> arr[i];
    cout << count0(arr) << "0s" << n - count0(arr) << "1s";
    return 0;
}
