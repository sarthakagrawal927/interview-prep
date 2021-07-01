class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            nums[i] = nums[j];
            i++;

            while (j < (nums.size() - 1) && nums[j] == nums[j + 1])
                j++;
        }
        return i;
    }
};