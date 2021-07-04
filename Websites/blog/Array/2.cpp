
// Check Subarray w 0 sum
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

bool check0Subarray(vll arr)
{
    unordered_set<int> set;
    int n = arr.size(), sum = 0;
    set.insert(0);

    REP(i, 0, n)
    {
        sum += arr[i];
        if (set.find(sum) != set.end())
            return true;
        else
            set.insert(sum);
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n;
    vll arr(n);
    REP(i, 0, n)
    cin >> arr[i];
    cout << check0Subarray(arr);
    return 0;
}
