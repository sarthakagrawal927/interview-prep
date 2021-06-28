// mean heap
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

void siftDown(int curr, int end, vector<int> &arr)
{
    int child1 = curr * 2 + 1, idxSwap;
    while (child1 <= end)
    {
        int child2 = (curr * 2 + 2 <= end) ? curr * 2 + 2 : -1;
        if (child2 > -1 && arr[child2] > arr[child1])
            idxSwap = child2;
        else
            idxSwap = child1;
        if (arr[idxSwap] > arr[curr])
        {
            swap(arr[curr], arr[idxSwap]);
            curr = idxSwap;
            child1 = curr * 2 + 1;
        }
        else
            return;
    }
}

void heapsort(vector<int> &arr)
{
    for (int i = arr.size() - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        siftDown(0, i - 1, arr);
    }
}

int main()
{
    vector<int> v1 = {8, 5, 2, 9, 5, 6, 3};

    make_heap(v1.begin(), v1.end());

    printVector(v1);
    heapsort(v1);
    printVector(v1);

    return 0;
}