// Power Set

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Space and Time complexity : n2^n - iterative
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> power;
    vector<int> single = {};

    power.push_back(single);

    for (int i = 0; i < a.size(); i++)
    {
        int n = power.size();
        for (int j = 0; j < n; j++)
        {
            single = power[j];
            single.push_back(a[i]);
            power.push_back(single);
        }
    }

    for (int i = 0; i < power.size(); i++)
    {
        for (int j = 0; j < power[i].size(); j++)
        {
            cout << power[i][j] << "  ";
        }
        cout << "\n";
    }
    return 0;
}
