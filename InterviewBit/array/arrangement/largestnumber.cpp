int myCompare(string X, string Y)
{
    string XY = X.append(Y);

    string YX = Y.append(X);

    return XY.compare(YX) > 0 ? 1 : 0;
}

string Solution::largestNumber(const vector<int> &A)
{
    vector<string> B;
    for (int i = 0; i < A.size(); i++)
    {
        B.emplace_back(to_string(A[i]));
    }
    sort(B.begin(), B.end(), myCompare);
    string s = "";
    for (int i = 0; i < B.size(); i++)
    {
        // cout << B[i] << " ";
        s += B[i];
    }
    if (s[0] == '0')
        return "0";
    return s;
}
