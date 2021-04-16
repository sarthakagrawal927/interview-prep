bool solve(string s)
{
    stack<char> stk;
    for (int x = 0; x < s.size(); x++)
    {
        if (s[x] == '(' || s[x] == '{' || s[x] == '[')
        {
            stk.push(s[x]);
        }
        else if (stk.size() <= 0)
            return false;
        else
        {
            char temp = stk.top();
            stk.pop();
            if (!((s[x] == (char)(temp + 1)) || (s[x] == (char)(temp + 2))))
            {
                return false;
            }
        }
    }
    return stk.size() == 0;
}