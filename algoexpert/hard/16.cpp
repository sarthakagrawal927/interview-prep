// Search for range

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int n = nums.size();

        int hi = n - 1, lo = 0;
        while (lo <= hi)
        {
            int m = (lo + hi) / 2;
            if (nums[m] == target)
            {
                cout << m << " ";
                if (m > 0 && nums[m - 1] == target)
                {
                    hi = m - 1;
                }
                else
                {
                    ans[0] = m;
                    break;
                }
            }
            else if (nums[m] < target)
            {
                lo = m + 1;
            }
            else
                hi = m - 1;
        }
        lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int m = (lo + hi) / 2;
            if (nums[m] == target)
            {
                cout << m << " ";
                if (m < n - 1 && nums[m + 1] == target)
                {
                    lo = m + 1;
                }
                else
                {
                    ans[1] = m;
                    break;
                }
            }
            else if (nums[m] < target)
            {
                lo = m + 1;
            }
            else
                hi = m - 1;
        }
        return ans;
    }
};