class Solution
{
public:
    int hasEvenDigits(int n)
    {
        int c = 0;
        cout << n << " ";
        while (n != 0)
        {
            c++;
            n /= 10;
        }
        cout << c << endl;
        return c % 2 == 0;
    }
    int findNumbers(vector<int> &nums)
    {
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hasEvenDigits(nums[i]))
                c++;
        }
        return c;
    }
};