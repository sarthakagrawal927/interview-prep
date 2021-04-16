int solve(string s)
{
    stack<char> stk;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(s[i]);
        else
        {
            if (stk.size() > 0)
                stk.pop();
            else
                count++;
        }
    }
    return count + stk.size();
}