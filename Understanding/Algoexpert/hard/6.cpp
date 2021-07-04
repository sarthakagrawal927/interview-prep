// Longest Common Subsequence

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void print(vector<vector<string>> arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    string s1 = "zxqwyzw", s2 = "xwkzpw";
    s1 = " " + s1;
    s2 = " " + s2;
    int l1 = s1.size(), l2 = s2.size();

    vector<vector<string>> E;
    E.resize(l1);

    for (int row = 0; row < l1; row++)
    {
        E[row].resize(l2);
        for (int col = 0; col < l2; col++)
        {
            if (row == 0) // filling border with ""
                E[row][col] = "";

            else if (col == 0) // filling border with ""
                E[row][col] = "";

            else if (s1[row] == s2[col]) // if equal then remove the character from both string and add prev output
                E[row][col] = E[row - 1][col - 1] + s1[row];

            else // just take max of  above and left
                E[row][col] = E[row - 1][col].size() > E[row][col - 1].size() ? E[row - 1][col] : E[row][col - 1];

            cout << E[row][col] << " ";
        }
        cout << endl;
    }
    cout << E[l1 - 1][l2 - 1];

    return 0;
}