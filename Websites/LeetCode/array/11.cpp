class Solution
{
public:
    int maxArea(vector<int> &a)
    {
        int ans = 0;
        int start = 0, end = a.size() - 1;
        while (start < end)
        {
            if (a[start] >= a[end])
            {
                ans = max(ans, (end - start) * a[end]);
                end--;
            }
            else
            {
                ans = max(ans, (end - start) * a[start]);
                start++;
            }
        }
        return ans;
    }
};