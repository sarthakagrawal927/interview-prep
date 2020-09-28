#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string a, b, line;
    vector<int> ans;
    while (getline(std::cin, line))
    {
        a = line.substr(0, 6);
        b = line.substr(7, 12);
        cout << a << " " << b << endl;
        if (a.compare(b) < 0) //a is smaller than b
            ans.push_back(1);
        else
            ans.push_back(0);
    }
    for (auto i = ans.begin(); i < ans.end(); i++)
        cout << *i << endl;
    return (0);
}