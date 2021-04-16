int findNumberOfPairs(vector<int> a, vector<int> b, int sum)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if ((a[i] + b[j]) == sum)
                count++;
        }
    }
    return count;
}

int findNumberOfPairs(vector<int> arr1, vector<int> arr2, int x)
{
    int count = 0;

    unordered_set<int> s;
    for (int i = 0; i < arr1.size(); i++)
        s.insert(arr1[i]);

    for (int j = 0; j < arr2.size(); j++)
        if (s.find(x - arr2[j]) != s.end())
            count++;
    return count;
}

vector<int> arrayAssignmentAndSum(vector<int> a, vector<int> b, vector<vector<int>> queries)
{
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i].size() == 3)
        {
            a[queries[i][1]] = queries[i][2];
        }
        else
        {
            ans.push_back(findNumberOfPairs(a, b, queries[i][1]));
        }
    }
    return ans;
}
