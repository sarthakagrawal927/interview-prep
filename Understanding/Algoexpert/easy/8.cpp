// insertion sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {1,
                       2,
                       4,
                       232,
                       42,
                       23,
                       4,
                       3,
                       321};
    int n = arr.size(), temp, j;

    for (int i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}