
vector<int> Solution::plusOne(vector<int> &A)
{
    auto i = A.end() - 1;
    *i += 1;
    while (i >= A.begin() && *i == 10)
    {
        *i = 0;
        i--;
        *i += 1;
    }
    auto j = A.begin();
    if (*j == 10)
    {
        *j = 0;
        A.insert(A.begin(), 1);
    }
    return A;
}
