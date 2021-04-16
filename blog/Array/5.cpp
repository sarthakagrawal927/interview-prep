
// Check dupliaate
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

int checkDuplicate(vll arr)
{
    int n = arr.size();
    int sum1 = (n * (n - 1)) / 2, sum2 = 0;

    REP(i, 0, n)
    sum2 += arr[i];

    return sum2 - sum1;
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n;
    vll arr(n);
    REP(i, 0, n)
    cin >> arr[i];
    cout << checkDuplicate(arr);
    return 0;
}
