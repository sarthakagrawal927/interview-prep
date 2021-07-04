//FLOYD'S TORTOISE AND HARE
int Solution::repeatedNumber(const vector<int> &A)
{
    int tortoise = A[0];
    int hare = A[0];
    do
    {
        tortoise = A[tortoise];
        hare = A[A[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = A[0];
    while (tortoise != hare)
    {
        tortoise = A[tortoise];
        hare = A[hare];
    }

    return hare;
}
