int hasThis(string s, char r)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == r)
            return i;
    }
    return -1;
}

string equallyRearranging(string str)
{
    string output = "";
    int i = 0;
    while (str.size())
    {
        int ans = hasThis(str, 'W');
        if (ans != -1)
        {
            output = output + 'W';
            str.erase(ans, 1);
        }
        ans = hasThis(str, 'D');
        if (ans != -1)
        {
            output = output + 'D';
            str.erase(ans, 1);
        }
        ans = hasThis(str, 'L');
        if (ans != -1)
        {
            output = output + 'L';
            str.erase(ans, 1);
        }
    }

    return output;
}
