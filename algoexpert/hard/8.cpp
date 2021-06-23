// Water Area

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
for every index we find tallest left pillar and right pillar
Then water at the intex would be min(left,right) - height of pillar at this index
*/

void printVector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    int sum = 0;
    vector<int> pillars = {0, 12, 0, 0, 5, 0, 0, 13, 0, 0, 1, 1, 0, 3, 0};
    int n = pillars.size();
    vector<int> left(n, 0), right(n, 0);
    for (int i = 1; i < n; i++)
        left[i] = max(pillars[i - 1], left[i - 1]);

    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], pillars[i + 1]);

    printVector(left);
    printVector(right);

    for (int i = 0; i < n; i++)
    {
        int minHeight = min(left[i], right[i]);
        if (minHeight > pillars[i])
            sum = sum + minHeight - pillars[i];

        cout << sum << " ";
    }

    return 0;
}
