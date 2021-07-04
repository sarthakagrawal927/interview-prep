class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == 0)
            {
                int j = n - 1;
                while (j > i)
                {
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[i + 1] = 0;
                i++;
            }
        }
    }
};
//[1,0,2,3,0,4,5,0]