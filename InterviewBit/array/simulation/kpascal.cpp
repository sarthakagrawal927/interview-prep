vector<int> Solution::getRow(int A)
{

    vector<int> sol(A + 1);
    sol[0] = 1;
    for (int i = 1; i < A; i++)
    {
        sol[i] = (sol[i - 1] * (A + 1 - i)) / i;
    }
    sol[A] = 1;
    return sol;
}
