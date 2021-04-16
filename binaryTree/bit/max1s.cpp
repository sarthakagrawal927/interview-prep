int solve(int n)
{
    int maxi = 0, curr = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            curr++;
        }
        else
        {
            if (curr > maxi)
            {
                maxi = curr;
            }
            curr = 0;
        }
        n /= 2;
    }
    if (curr > maxi)
    {
        maxi = curr;
    }
    return maxi;
}