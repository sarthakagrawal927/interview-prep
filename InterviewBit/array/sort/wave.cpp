vector<int> Solution::wave(vector<int> &A)
{
    sort(A.begin(), A.end());
    for (auto i = A.begin(); i < A.end(); i = i + 2)
    {
        if (i == A.end() - 1)
            return A;
        swap(*i, *(i + 1));
    }
    return A;
}
