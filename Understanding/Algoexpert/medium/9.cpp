// mimumum number of coins to make change

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int target = 23423, latest;
    vector<int> coins = {3, 4};
    vector<int> minCoins(target + 1, 1e8);

    minCoins[0] = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= target; j++)
        {
            latest = 1 + minCoins[j - coins[i]];
            minCoins[j] = min(minCoins[j], latest);
        }
    }

    cout << minCoins[target] << endl;
    return 0;
}
