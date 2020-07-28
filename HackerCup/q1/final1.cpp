#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
#define rep(i, j, n) for (auto i = j; i < n; i++)
#define reprev(i, j, n) for (auto i = n; i > 0 i--)

void printMatrix(vector<vector<char>> arr, int m)
{
    rep(i, 0, m)
    {
        rep(j, 0, m) cout << arr[i][j] << "  ";
        cout << endl;
    }
}
/*
Asus@Sarthak MINGW64 /z/Coding/CompetetiveCoding/hackercup (master)
$ ./a
5
1 0 0 1 1
1 1 1 0 1

1  0  0  0  0  
1  1  0  0  0
1  0  1  1  0
0  0  0  1  0
1  0  0  1  1

1  0  0  0  0  
1  1  0  0  0
0  0  1  1  0
0  0  0  1  0
0  0  0  1  1
*/

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> output(n, vector<char>(n, 'P')); //int output[50][50] = {-1};
    string incoming;                                      //int incoming[50];
    string outgoing;                                      //int outgoing[50];

    cin >> incoming;
    cin >> outgoing;
    cout << incoming << " " << outgoing << "\n";
    int stopped = 0;
    rep(i, 0, n)
    {
        if (outgoing[i] == 'N')
        {
            rep(j, 0, n)
            {
                if (i == j)
                    output[i][j] = 'Y';
                else
                    output[i][j] = 'N';
            }
        }
        else
        {
            for (int j = i; j < n; ++j) //Try going right
            {
                if (stopped == 1)
                    output[i][j] = 'N';

                if (outgoing[j] == 'Y' && incoming[j + 1] == 'Y' && stopped == 0)
                    output[i][j + 1] = 'Y';
                else
                    stopped = 1;

                if (i == j)
                    output[i][j] = 'Y';
            }
            stopped = 0;
            for (int j = i; j > 0; --j) //Try going left
            {
                if (stopped == 1)
                    output[i][j] = 'N';

                if (outgoing[j] == 'Y' && incoming[j - 1] == 'Y' && stopped == 0)
                    output[i][j - 1] = 'Y';
                else
                    stopped = 1;

                if (i == j)
                    output[i][j] = 'Y';
            }
            stopped = 0;
        }
    }
    printMatrix(output, n);
}
