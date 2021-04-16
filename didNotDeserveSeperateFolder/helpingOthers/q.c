#include <stdio.h>
int main()
{
    int a[100];
    int d = 0, count = 0, ans = 0;
    while (d != -1)
    {
        scanf("%d", &d);
        a[count++] = d;
    }
    count--;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (a[j] < a[i])
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}