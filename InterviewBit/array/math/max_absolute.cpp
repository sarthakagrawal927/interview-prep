int Solution::maxArr(vector<int> &A)
{
    int maxi = 0, max1 = -1e9, max2 = -1e9, min1 = 1e9, min2 = 1e9;
    for (int i = 0; i < A.size(); i++)
    // [ 1, 3, -1]
    {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }
    return max(max1 - min1, max2 - min2);
}

//Not so good approach, time limit exceeded

int Solution::maxArr(vector<int> &A)
{
    int m = INT_MIN, d1, d2;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            d1 = abs(i - j);
            d2 = abs(A[i] - A[j]);
            m = max(m, d1 + d2);
        }
    }
    return m;
}
