// 2 number sum

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[5] = {1, 3, 2, 4, 9}, target = 8;
    unordered_map<int, int> umap;
    for (int i = 0; i < 5; i++)
    {
        if (umap.find(target - arr[i]) != umap.end())
            cout << "found";
        else
        {
            // cout << "Not found,inserted " << arr[i];
            umap[i] = arr[i];
        }
    }

    return 0;
}