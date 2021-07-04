vector<int> ans(vector<int> &A)
{
    auto i = A.begin();
    while (*i == 0)
    {
        A.erase(A.begin());
        i = A.begin();
    }
    return A;
}

vector<int> Solution::plusOne(vector<int> &A)
{
    auto i = A.end() - 1;
    *i += 1;
    while (*i == 10)
    {

        *i = 0;
        i--;
        if (i < A.begin())
        {
            auto j = A.insert(A.begin(), 1);
            return ans(A);
        }
        *i += 1;
    }
    return ans(A);
}
