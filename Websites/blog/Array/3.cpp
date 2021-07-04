
// Print Subarray w 0 sum
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

void printAll0Subarray(vll arr)
{
    unordered_multimap<int, int> map;
    int n = arr.size(), sum = 0;
    map.insert(pair<int, int>(0, -1)); //to  count cases with 0 in start
    REP(i, 0, n)
    {
        sum += arr[i];
        if (map.find(sum) != map.end())
        {
            auto it = map.find(sum);
            while (it != map.end() && it->first == sum)
            {
                REP(j, it->second + 1, i + 1)
                {
                    cout << arr[j] << " ";
                }
                cout << '\n';
                it++;
            }
        }
        map.insert(pair<int, int>(sum, i));
    }
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n;
    vll arr(n);
    REP(i, 0, n)
    {
        cin >> arr[i];
    }
    printAll0Subarray(arr);
    return 0;
}
