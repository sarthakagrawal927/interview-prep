
// Find Pair with given sum
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sum;

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.find(sum - arr[i]) != map.end())
            cout << arr[i] << " " << sum - arr[i];
        map[arr[i]] = i;
    }
    return 0;
}
