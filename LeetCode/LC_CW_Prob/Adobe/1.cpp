class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> V;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] + nums[i] == target)
                {
                    V.push_back(i);
                    V.push_back(j);
                    return V;
                }
            }
        }
        return V;
    }
};