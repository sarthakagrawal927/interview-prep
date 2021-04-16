class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;
        int currSum = 0;
        int minlen = INT_MAX;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            while (currSum >= target)
            {
                ans = min(minlen, i - start + 1);
                minlen = ans;
                currSum -= nums[start];
                start++;
            }
        }
        return ans;
    }
};