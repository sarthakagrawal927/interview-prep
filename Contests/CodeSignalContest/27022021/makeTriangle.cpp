bool getMax(int a, int b, int c)
{
    vector<int> ar;
    ar.push_back(a);
    ar.push_back(b);
    ar.push_back(c);
    sort(ar.begin(), ar.end());
    return (ar[2] < (ar[0] + ar[1]));
}

vector<int> canMakeTriangle(vector<int> arr)
{
    vector<int> ans(arr.size() - 2);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < (arr.size() - 2); i++)
    {
        a = arr[i], b = arr[i + 1], c = arr[i + 2];
        ans[i] = getMax(a, b, c);
    }
    return ans;
}
