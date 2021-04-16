class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int l1 = nums1.size(), l2 = nums2.size();
        vector<int> merged;
        int i = 0, j = 0;
        while (i < l1 && j < l2)
        {
            if (nums1[i] > nums2[j])
                merged.push_back(nums2[j++]);
            else
                merged.push_back(nums1[i++]);
        }
        while (i < l1)
        {
            merged.push_back(nums1[i++]);
        }
        while (j < l2)
        {
            merged.push_back(nums2[j++]);
        }
        if ((l1 + l2) == 1)
            return (double)merged[0];
        if (merged.size() % 2 == 0)
        {
            return ((double)merged[(l1 + l2) / 2 - 1] + (double)merged[(l1 + l2) / 2]) / 2;
        }
        else
            return (double)merged[(l1 + l2) / 2];
    }
};