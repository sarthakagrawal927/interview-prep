bool isPrime(int n)
{

    if (n <= 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
vector<int> Solution::primesum(int A)
{
    vector<int> ans;
    for (int i = 2; i < A; i++)
    {
        if (isPrime(i))
        {
            if (isPrime(A - i))
            {
                ans.push_back(min(i, A - i));
                ans.push_back(max(i, A - i));
                return ans;
            }
        }
    }
}
