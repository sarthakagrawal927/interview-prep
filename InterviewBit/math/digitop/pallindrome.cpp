int reverse(int a)
{
    int s = 0;
    while (a != 0)
    {
        s = s * 10 + a % 10;
        a /= 10;
    }
    return s;
}

int Solution::isPalindrome(int A)
{
    if (A < 0)
        return 0;
    return A == reverse(A);
}
