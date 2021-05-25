// Permutations

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Space and Time complexity : n2^n - iterative
void getpermutations(vector<int> a, vector<int> perm, vector<vector<int>> perms)
{
    vector<int> newPerm, newArr;
    if (a.size() == 0)
    {
        for (int i = 0; i < perm.size(); i++)
            cout << perm[i] << " ";
        cout << endl;
        perms.push_back(perm);
    }
    else
    {
        for (auto i = a.begin(); i < a.end(); i++)
        {
            newPerm.push_back(*i);
            newArr = a;

            newArr.erase(i - a.begin() + newArr.begin());
            getpermutations(newArr, newPerm, perms);
        }
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 4};

    vector<int> perm(a.size());
    vector<vector<int>> perms;

    vector<int> arr = a;

    getpermutations(arr, perm, perms);

    cout << perms.size();

    return 0;
}
