class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// O(n)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int s = 0, e = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {

            if (abs(nums[s]) > nums[e])
            {
                ans[i] = nums[s] * nums[s];
                s++;
            }
            else
            {
                ans[i] = nums[e] * nums[e];
                e--;
            }
        }
        return ans;
    }
};