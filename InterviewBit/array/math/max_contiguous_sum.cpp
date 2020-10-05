int Solution::maxSubArray(const vector<int> &A)
{
    int curr_sum = 0, max_sum = -1e9;
    for (auto i = A.begin(); i < A.end(); i++)
    {
        curr_sum += *i;
        if (curr_sum > max_sum)
            max_sum = curr_sum;
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}
