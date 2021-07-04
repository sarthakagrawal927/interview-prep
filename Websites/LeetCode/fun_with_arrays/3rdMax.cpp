class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        if (nums.size() == 2)
            return max(nums[1], nums[0]);
        else if (nums.size() == 1)
            return nums[0];

        long long int m = -1e10, m1 = -1e10, m2 = -1e10;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m < nums[i])
                m = nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (m1 < nums[i] && nums[i] != m)
                m1 = nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (m2 < nums[i] && nums[i] != m && nums[i] != m1)
                m2 = nums[i];
        }

        cout << m << m1 << m2;
        if (m2 == -1e10)
        {
            return m;
        }
        return m2;
    }
};