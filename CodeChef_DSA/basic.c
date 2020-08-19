#include<stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while (t-->0) {
        long long int k, sum;
        int d0, d1, dig, i, x;
        scanf("%lld%d%d", &k, &d0, &d1);
        sum=d0+d1;
        if (k>2&&sum!=10)
        {
            sum=sum+(sum%10);
            if (sum!=20&&sum!=10) {
                sum=sum+(20*((k-3)/4));
                x=(k-3)%4;
                for (i=1;i<=x;i++) {
                    dig=sum%10;
                    if (dig==0) break;
                    sum+=dig;
                }
            }
        }
        if (sum%3==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}