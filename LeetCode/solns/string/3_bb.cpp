int offsets[128] = {0};

int lengthOfLongestSubstring(const string &s)
{
    int res = 0, last = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        last = max(last, offsets[s[i]]);
        res = max(res, i - last + 1);
        offsets[s[i]] = i + 1;
    }

    return res;
}