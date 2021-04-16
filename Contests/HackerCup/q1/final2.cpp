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
        rep(j, 0, m)
        {
            if (arr[i][j] == 0)
                cout << 'N';
            else
                cout << 'Y';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int output[50][50] = {-3};
    int incoming[50];
    int outgoing[50];

    string inc; //int incoming[50];
    string out; //int outgoing[50];

    cin >> inc;
    cin >> out;

    rep(i, 0, inc.length())
    {
        if (inc[i] == 'Y')
            incoming[i] = 1;
        else
            incoming[i] = 0;
    }
    rep(i, 0, out.length())
    {
        if (out[i] == 'Y')
            outgoing[i] = 1;
        else
            outgoing[i] = 0;
    }
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
