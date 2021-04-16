class Solution
{
public:
    bool checkPalindromeFormation(string a, string b)
    {
        int n = a.size();
        if (n == 1)
            return true;

        return (a[0] == b[n - 1]) || (a[n - 1] == b[0]);
    }
};