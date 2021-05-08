// selection sort

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

    for (int i = 0; i < n; i++)
    {
        int min0 = 1e8, mini = i;
        for (int j = i; j < n; j++)
        {
            if (min0 > arr[j])
                mini = j, min0 = arr[j];
        }
        temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}