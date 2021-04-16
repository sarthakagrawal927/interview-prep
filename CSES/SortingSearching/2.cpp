// https://cses.fi/problemset/task/1084

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long int

#define print(v)                               \
    for (auto i = v.begin(); i < v.end(); i++) \
        cout << *i << " ";                     \
    cout << endl;

#define takeinput(v, n, temp)  \
    for (ll i = 0; i < n; i++) \
    {                          \
        cin >> temp;           \
        v.push_back(temp);     \
    }

#define lb cout << endl

bool inBetween(ll low, ll up, ll req)
{
    return low <= req && req <= up;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k, temp, count = 0;
    cin >> n >> m >> k;
    vector<ll> app, apt;

    takeinput(apt, n, temp);
    takeinput(app, m, temp);

    sort(apt.begin(), apt.end());
    sort(app.begin(), app.end());

    //lb;

    //print(apt);
    //print(app);

    auto j = apt.begin();

    for (auto i = app.begin(); i < app.end();)
    {
        // cout << *i << " is in between" << *j - k << " and " << *j + k << endl;

        if (inBetween(*j - k, *j + k, *i))
        { //room alloted
            //cout << *i << " *** is in between" << *j - k << " and " << *j + k << endl;
            i++;
            count++;
            j++;
        }
        else if ((*j - k) > *i)
            i++;
        else if ((*j + k) < *i)
            j++;

        if (j == apt.end())
            break;
    }
    cout << count;
    return 0;
}