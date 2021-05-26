// number of ways to make change

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int target = 10;
    vector<int> coins = {1, 2, 5, 10, 20};
    vector<int> ways(target + 1, 0);
    ways[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= target; j++)
            ways[j] += ways[j - coins[i]];
    }
    cout << ways[target];

    return 0;
}
