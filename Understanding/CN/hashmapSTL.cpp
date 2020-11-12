#include <iostream>
#include <map>           //BST logn
#include <unordered_map> //hashmap o(1)
#include <vector>
#include <string>
#include <iterator>
using namespace std;
vector<int> removeDups(int *a, int size)
{
    vector<int> ans;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
            continue;
        seen[a[i]] = true;
        ans.push_back(a[i]);
    }
    return ans;
}
int main()
{
    unordered_map<string, int> ourMap;

    pair<string, int> p("abc", 1);

    //insert
    ourMap.insert(p);
    ourMap["aba"] = 2;
    ourMap["asba"] = 3;
    ourMap["aba2"] = 4;
    ourMap["ab3a"] = 8;
    ourMap["aba1"] = 7;
    ourMap["ab2a"] = 1;

    unordered_map<string, int>::iterator it;
    for (it = ourMap.begin(); it != ourMap.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    // find
    cout << ourMap["ghi"];    //when accessing undefined key, it makes it and initialized it with 0
    cout << ourMap.at("ghi"); //gives error when accessing undefined key
    // so both sucks

    if (ourMap.count("ghi") > 0)
    {
        cout << "presen";
    }

    ourMap.erase("ghi");
    if (ourMap.count("ghi") > 0)
    {
        cout << "presen";
    }
    return 0;
}