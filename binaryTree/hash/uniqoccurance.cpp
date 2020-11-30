bool solve(vector<int> &nums)
{
    // Insert all elements in hash.
    int n = nums.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) //getting occurances of all elements
        hash[nums[i]]++;

    unordered_set<int> s;
    for (auto i : hash)
    {
        if (s.find(i.second) == s.end()) // making sure they are unique
            s.insert(i.second);
        else
            return false;
    }

    return true;
}
