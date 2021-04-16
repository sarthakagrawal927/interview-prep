int solve(vector<int> &nums)
{
    // Insert all elements in hash.
    int n = nums.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[nums[i]]++;

    // find the max frequency
    int max_count = 0;
    for (auto i : hash)
    {
        if (max_count < i.second)
        {
            max_count = i.second;
        }
    }
    return max_count;
}
