class Solution
{
public:
    int maxDepth(string s)
    {
        int maxi = 0, count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if ((char)s[i] == '(')
                count++;
            else if ((char)s[i] == ')')
                count--;
            if (count > maxi)
                maxi = count;
        }
        return maxi;
    }
};