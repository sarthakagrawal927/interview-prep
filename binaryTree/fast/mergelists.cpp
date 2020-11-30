vector<int> solve(vector<int> &lst0, vector<int> &lst1)
{
    int len1 = lst0.size(), len2 = lst1.size();
    vector<int> ans;
    int i = 0, j = 0;
    while (i < len1 || j < len2)
    {
        if (i == len1)
        {
            ans.push_back(lst1[j++]);
        }
        else if (j == len2)
        {
            ans.push_back(lst0[i++]);
        }
        else if (lst0[i] >= lst1[j])
        {
            ans.push_back(lst1[j]);
            j++;
        }
        else if (lst0[i] <= lst1[j])
        {
            ans.push_back(lst0[i]);
            i++;
        }
    }
    return ans;
}