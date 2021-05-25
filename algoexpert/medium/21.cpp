// Longest Pallindromic string

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s = "abaxyzozyxf";
    int n = s.size(), max_till = 0, curr_size = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i - 1, right = i + 1;
        curr_size = 1;
        // odd size pallindrome
        while (left >= 0 && right < n && s[left] == s[right])
        {
            curr_size += 2;
            left--;
            right++;
        }

        if (i < n - 1 && s[i] == s[i + 1]) // even
        {
            curr_size = 2, left = i - 1, right = i + 2;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                curr_size += 2;
                left--;
                right++;
            }
        }

        max_till = max(max_till, curr_size);
    }
    cout << max_till;

    return 0;
}