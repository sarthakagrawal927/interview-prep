class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> box;
        string w = s;
        int m = 0;
        int n = s.size(), j;
        for (int i = 0; i < n; i++)
        {
            if (box.find(s[i]) != box.end())
            {
                j = i - 1;
                box.clear();
                while (j >= 0 && w[j] != s[i])
                {
                    box.insert(w[j--]);
                }
            }
            box.insert(s[i]);
            m = m > box.size() ? m : box.size();
        }
        return m;
    }
};