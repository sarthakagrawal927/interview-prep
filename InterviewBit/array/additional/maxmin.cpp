int Solution::solve(vector<int> &A)
{
    return *max(A.begin(), A.end()) + *min(A.begin(), A.end());
}
