//https://www.codechef.com/AUG20B/problems/CHEFWARS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)
#define test    \
    int T_T;    \
    cin >> T_T; \
    while (T_T--)

int main()
{
    vector<int> ans;
    int t;
    cin >> t;
    while (t--)
    {
        int chef_health, darth_health, chef_attack = 0;
        cin >> darth_health >> chef_health;
        while (chef_health > 0)
        {
            chef_attack += chef_health;
            chef_health /= 2;
        }
        if (chef_attack >= darth_health)
            ans.push_back(1);
        else
            ans.push_back(0);
    }

    for (auto i = ans.begin(); i < ans.end(); i++)
        cout << *i << "\n";
    return -1;
}