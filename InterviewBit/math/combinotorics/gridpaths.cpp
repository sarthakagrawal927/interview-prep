int getPaths(int a, int b)
{
    if (a == 1 || b == 1)
        return 1;
    return getPaths(a - 1, b) + getPaths(a, b - 1);
}

int Solution::uniquePaths(int A, int B)
{
    return getPaths(A, B);
}
