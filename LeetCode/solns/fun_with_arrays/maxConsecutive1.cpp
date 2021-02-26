class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int i = 0, n = nums.size(), m = 0, c = 0;
        while (i < n)
        {
            cout << nums[i] << " ";
            if (nums[i] == 1)
                c++;
            else
            {
                if (c > m)
                    m = c;
                c = 0;
            }
            i++;
        }
        if (c > m)
            m = c;
        return m;
    }
};