int solve(string s)
{
    stack<char> stk;
    int count = 0;
    for (int x = 0; x < s.size(); x++)
    {
        if (s[x] == '(')
            stk.push(s[x]);
        else if (stk.size() > 0)
        {
            stk.pop();
            count += 2;
        }
    }
    return count;
}