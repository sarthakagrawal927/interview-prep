
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
#define ll long long int
#define rep(i, j, n) for (ll i = j; i < n; i++)

void show(int a[])
{
    rep(i, 0, 10) cout << a[i] << " ";
}

int main()
{
    int a[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 3};
    int asize = sizeof(a) / sizeof(a[0]);
    // sort(a, a + asize);
    // if (binary_search(a, a + asize, 4))
    //     cout << "\n found";
    // cout << "\n\n The array after sorting is : ";
    // show(a);

    vector<int> vect(a, a + asize);
    // reverse(vect.begin(), vect.end());
    rep(i, 0, asize) cout << vect[i] << " ";

    // cout << *max_element(a, a + asize) << " ";
    // cout << *max_element(vect.begin(), vect.end()) << " ";

    // cout << accumulate(a, a + asize, 0);
    // cout << accumulate(vect.begin(), vect.end(), 0);

    // cout << count(a, a + asize, 3);
    // cout << count(vect.begin(), vect.end(), 3);

    // (*find(a, a + asize, 5)) != (asize - 1) ? cout << "\nElement found" : cout << "\nElement not found";
    // find(vect.begin(), vect.end(), 5) != vect.end() ? cout << "\nElement found" << endl : cout << "\nElement not found" << endl;

    auto upperbound = upper_bound(vect.begin(), vect.end(), 40);
    auto lowerbound = lower_bound(vect.begin(), vect.end(), 40);

    cout << "first pos " << (upperbound - vect.begin()) << " last position " << (lowerbound - vect.begin()) << endl;

    return 0;
}
