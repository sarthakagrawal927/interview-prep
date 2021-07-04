int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    auto i = A.begin();
    auto j = B.begin();
    int count = 0, x = *i, y = *j;
    i++;
    j++;
    for (; i < A.end(); i++, j++)
    {
        int x_next = *i, y_next = *j;
        int x_diff = abs(x_next - x), y_diff = abs(y_next - y);
        count += abs(x_diff - y_diff) + min(x_diff, y_diff);
        x = x_next;
        y = y_next;
    }
    return count;
}
