// Permutations

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void print2DVector(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void getpermutations(int i, vector<int> &a, vector<vector<int>> &perms)
{
    if (i == a.size() - 1)
        perms.push_back(a);
    else
        for (int j = i; j < a.size(); j++)
        {
            swap(a, i, j);
            getpermutations(i + 1, a, perms);
            swap(a, i, j);
        }
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> perms;

    getpermutations(0, a, perms);
    print2DVector(perms);
    cout << perms.size() << endl;
    return 0;
}
