#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

long long int fib_memo(int n, long long int *arr) //top-down Memoization
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    if (arr[n - 1] == -1)
        arr[n - 1] = fib_memo(n - 1, arr);
    if (arr[n - 2] == -1)
        arr[n - 2] = fib_memo(n - 2, arr);

    arr[n] = arr[n - 1] + arr[n - 2];
    return arr[n];
}

long long int fib_dp(int n) //Bottom-up DP
{
    long long int *ans = new long long int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();

    start = high_resolution_clock::now();
    long long int *arr = new long long int[n + 1];
    for (long long int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    cout << fib_dp(n) << endl;
    stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "dp: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    cout << fib_memo(n, arr) << endl;
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    cout << "memo: " << duration.count() << " microseconds" << endl;

    return 0;
}
