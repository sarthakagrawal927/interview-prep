//https://www.geeksforgeeks.org/count-the-number-of-ways-to-divide-an-array-into-three-contiguous-parts-having-equal-sum/
int Solution::solve(int A, vector<int> &B)
{
    int count = 0, cnt[A] = {0};
    long long int s = 0;

    for (int i = 0; i < A; i++)
        s += B[i];

    if (s % 3 != 0)
        return count;
    long long int ss = 0;
    s /= 3;

    for (int i = A - 1; i >= 0; i--)
    {
        ss += B[i];
        if (ss == s)
            cnt[i] = 1;
    }

    ss = 0;
    for (int i = A - 2; i >= 0; i--)
    {
        cnt[i] += cnt[i + 1];
    }

    for (int i = 0; i < A - 2; i++)
    {
        ss += B[i];
        if (ss == s)
        {
            count += cnt[i + 2];
        }
    }

    return count;
}
