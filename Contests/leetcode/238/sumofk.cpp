class Solution
{
public:
    int sumDigits(int n)
    {
        cout << n;
        int sum = 0;
        while (n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int sumBase(int n, int k)
    {
        if (k != 10)
        {
            int temp = n, sum = 0, dig;
            while (temp != 0)
            {
                sum = sum * 10 + temp % k;
                temp = temp / k;
            }
            return sumDigits(sum);
        }
        return sumDigits(n);
    }
};