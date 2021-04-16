class Solution
{
public:
    int maxProfit(vector<int> &nums)
    {
        int bp = 9999999, profit = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (bp > nums[i])
                bp = nums[i];
            else if (nums[i] - bp > profit)
                profit = nums[i] - bp;
        }
        return profit;
    }
};