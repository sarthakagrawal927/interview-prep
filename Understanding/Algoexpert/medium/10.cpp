// Levenshtein Distance
// minimum operations needed to convert 1 to other

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void print(vector<vector<int>> arr, int row, int col)
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

// o(mn), space: o(mn) , space can be better by O(min(m,n))
int main()
{
    string s1 = "abc", s2 = "yabd";
    s1 = " " + s1;
    s2 = " " + s2;
    int l1 = s1.size(), l2 = s2.size();

    vector<vector<int>> E(l1, vector<int>(l2, 0));

    for (int row = 0; row < l1; row++)
    {
        for (int col = 0; col < l2; col++)
        {
            if (row == 0)
                E[row][col] = col; //getting first row as {0,1,2,3,4, ...}

            else if (col == 0)
                E[row][col] = row; //getting first col as {0,1,2,3,4, ...}

            else if (s1[row] == s2[col])
                E[row][col] = E[row - 1][col - 1];

            else
                E[row][col] = 1 + min(E[row - 1][col - 1], min(E[row - 1][col], E[row][col - 1]));
        }
        print(E, l1, l2);
    }
    cout << E[l1 - 1][l2 - 1];

    return 0;
}