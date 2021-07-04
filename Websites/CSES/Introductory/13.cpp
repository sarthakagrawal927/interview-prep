// https://cses.fi/problemset/task/1622
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<string> s;
void permute(string a, int l, int r)
{
    if (l == r)
        s.push_back(a);
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    string str;
    cin >> str;
    int arr[26] = {0};
    for (auto i = 0; i < str.size(); i++)
    {
        arr[(int)str[i] - 97]++;
    }
    int f = fact(str.size());
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 1)
            f /= fact(arr[i]);
    }
    permute(str, 0, str.size() - 1);
    cout << f << endl;
    sort(s.begin(), s.end());
    set<string> s1;

    for (auto i = s.begin(); i < s.end(); i++)
    {
        s1.insert(*i);
    }
    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i << endl;
    }

    return 0;
}
