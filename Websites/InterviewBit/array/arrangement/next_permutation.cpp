vector<int> Solution::nextPermutation(vector<int> &A)
{

    int N = A.size();
    int x = -1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            x = i;
            break;
        }
    }
    if (x == -1)
    {

        sort(A.begin(), A.end());
        return A;
    }
    sort(A.begin() + x + 1, A.end());
    for (int i = x + 1; i < N; i++)
    {
        if (A[i] > A[x])
        {
            swap(A[i], A[x]);
            break;
        }
    }

    return A;
}