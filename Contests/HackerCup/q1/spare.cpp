#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
#define rep(i, j, n) for (auto i = j; i < n; i++)
#define reprev(i, j, n) for (auto i = n; i > 0 i--)

void printMatrix(int arr[][50], int m)
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
    int output[50][50] = {-3};
    int incoming[50];
    int outgoing[50];

    rep(i, 0, n) cin >> incoming[i];
    rep(i, 0, n) cin >> outgoing[i];
    cout << endl;
    int stopped = 0;
    rep(i, 0, n)
    {
        if (outgoing[i] == 0)
        {
            rep(j, 0, n)
            {
                if (i == j)
                    output[i][j] = 1;
                else
                    output[i][j] = 0;
            }
        }
        else
        {
            for (int j = i; j < n; ++j) //Try going right
            {
                if (stopped == 1)
                    output[i][j] = 0;

                if (outgoing[j] == 1 && incoming[j + 1] == 1 && stopped == 0)
                    output[i][j + 1] = 1;
                else
                    stopped = 1;

                if (i == j)
                    output[i][j] = 1;
            }
            stopped = 0;
            for (int j = i; j > 0; --j) //Try going left
            {
                if (stopped == 1)
                    output[i][j] = 0;

                if (outgoing[j] == 1 && incoming[j - 1] == 1 && stopped == 0)
                    output[i][j - 1] = 1;
                else
                    stopped = 1;

                if (i == j)
                    output[i][j] = 1;
            }
            stopped = 0;
        }
    }
    printMatrix(output, n);
}

/* Condition dekh ek baar
 It’s possible to visit the city in incoming is allowed and outgoing is not
 Tera condition nahi satisfy karra
 Inc[j+1] != 0 OR out[j] != 0
 Yeh hai*/