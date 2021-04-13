#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> a, int n)
{
    int start = 0, end = n - 1;
    if (n <= 1)
        return true;
    if (a[start] != 1)
        return 0;
    while (start < end)
    {
        if (a[start] != a[end])
            return false;
        if ((a[start + 1] - a[start]) > 1)
            return false;
        if ((a[end - 1] - a[end]) > 1)
            return false;

        start++;
        end--;
    }
    if (a[start] != 7)
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    int t, n, temp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    vector<int> arr;
    while (t--)
    {
        cin >> n;
        int size = n;
        while (n--)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        check(arr, size) ? cout << "yes\n" : cout << "no\n";
        arr.clear();
    }
    return 0;
}
