class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size();
        int min_product_end_here = 1;
        int max_product_end_here = 1;
        int max_product = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                int t = min_product_end_here;
                min_product_end_here = min(arr[i], max_product_end_here * arr[i]);
                max_product_end_here = max(arr[i], t * arr[i]);
            }
            else if (arr[i] == 0)
            {
                min_product_end_here = 0;
                max_product_end_here = 0;
            }
            else
            {
                max_product_end_here = max(arr[i], max_product_end_here * arr[i]);
                min_product_end_here = min(arr[i], min_product_end_here * arr[i]);
            }
            max_product = max(max_product, max_product_end_here);
        }
        return max_product;
    }
};