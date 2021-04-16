class Solution
{
public:
    bool isPalindrome(string s)
    {
        s.erase(
            std::remove_if(
                s.begin(),
                s.end(),
                [](const char &c) { return (::ispunct(c) || isspace(c)); }),
            s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
};