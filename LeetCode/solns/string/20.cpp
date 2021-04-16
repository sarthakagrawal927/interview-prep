class Solution
{
public:
    bool isClose(char s)
    {
        return s == ']' || s == '}' || s == ')';
    }

    bool isValid(string s)
    {
        stack<char> st;
        int n = s.size();
        char t;
        if (isClose(s[0]))
            return 0;
        st.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (isClose(s[i]))
            {
                if (st.size() == 0)
                    return 0;
                t = st.top();
                st.pop();
                if (t == '[')
                    if (s[i] != ']')
                        return 0;
                if (t == '{')
                    if (s[i] != '}')
                        return 0;
                if (t == '(')
                    if (s[i] != ')')
                        return 0;
            }
            else
                st.push(s[i]);
        }
        return st.size() == 0;
    }
};