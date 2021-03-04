class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
                return 1;
            m.insert(nums[i]);
        }
        return 0;
    }
};