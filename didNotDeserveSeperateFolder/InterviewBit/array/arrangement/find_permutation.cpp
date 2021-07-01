vector<int> Solution::findPerm(const string A, int B)
{
    vector<int> out;
    int start = 1, end = B;

    for (int i = 0; i < B; i++)
    {
        if (A[i] == 'I')
            out.push_back(start++);
        else
            out.push_back(end--);
    }
    return out;
}
