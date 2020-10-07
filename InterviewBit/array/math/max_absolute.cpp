int Solution::maxArr(vector<int> &A)
{
    int maxi = 0, sum, max1 = -1e9, max2 = -1e9, min1 = 1e9, min2 = 1e9;
    for (int i = 0; i < A.size(); i++)
    {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }
    return max(max1 - min1, max2 - min2);
}
