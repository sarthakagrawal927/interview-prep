// https://cses.fi/problemset/task/1621

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> st;
    long long int n, no;
    cin >> n;
    while (n--)
    {
        cin >> no;
        st.insert(no);
    }
    cout << st.size();
    return 0;
}