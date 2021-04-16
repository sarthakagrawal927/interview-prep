
// Find max length subarray
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long int
#define vll vector<ll>
#define REP(i, a, b) for (auto i = a; i < b; i++)

using namespace std;

void findMaxLenSubarray(int arr[], int n, int S)
{
    int n = arr.size();
    int sum1 = (n * (n - 1)) / 2, sum2 = 0;

    REP(i, 0, n)
    sum2 += arr[i];
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int sum = 8;

    int n = sizeof(arr) / sizeof(arr[0]);

    findMaxLenSubarray(arr, n, sum);
    return 0;
}
