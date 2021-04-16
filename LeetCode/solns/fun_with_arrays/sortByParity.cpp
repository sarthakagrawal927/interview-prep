class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        vector<int> v(A.size());
        int s = 0, e = A.size() - 1;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2)
                v[e--] = A[i];
            else
                v[s++] = A[i];
        }
        return v;
    }
};