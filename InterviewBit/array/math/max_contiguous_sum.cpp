int Solution::maxSubArray(const vector<int> &A)
{
    int curr = 0, ma = -1e7;
    for (int i = 0; i < A.size(); i++)
    {
        curr += A[i];
        curr = max(curr, A[i]);
        ma = max(curr, ma);
    }
    return ma;
}
