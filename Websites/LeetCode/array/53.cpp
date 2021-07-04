class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int cm = nums[0], mv = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            cm = max(nums[i], cm + nums[i]);
            mv = max(mv, cm);
        }

        return mv;
    }
};