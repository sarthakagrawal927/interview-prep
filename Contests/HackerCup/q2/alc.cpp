#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define rep(i, j, n) for (auto i = j; i < n; i++)
#define reprev(i, j, n) for (auto i = n; i > 0 i--)

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> pricePerGallon(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> pricePerGallon[i];
    }
    int start = 0, end = m, maxend = 0, petrol = m, n = pricePerGallon.size(); // petrol is measured in gallons and is current petrol left in tank
    int cost = 0;

    while (end < n)
    {
        petrol--;
        for (int i = start; i <= end; i++)
        {
            //cost = *min_element(pricePerGallon.begin() + start, pricePerGallon.begin() + end)*(m-petrol);
            idx = (index of above min_element expression);
        }

        petrol += cost / pricePerGallon[2];
        start = end;
        end = petrol;

        //cout << start << " " << end << "\n";
    }
    return cost;
}
