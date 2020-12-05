#include <stdio.h>
#include <string.h>
int main()
{
    float x, y;
    int count = 0;
    float arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("(%f %f) ", &x, &y);
            arr[i][j] = y;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == -arr[j][i])
                count++;
        }
    }
}