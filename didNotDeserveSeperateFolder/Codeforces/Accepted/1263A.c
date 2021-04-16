#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
  int count = 0;
  int n;
  scanf("%d\n", &n);
  int a1[10000], b1[10000], c1[10000];
  for (int i = 0; i < n; i++)
    scanf("%d %d %d", &a1[i], &b1[i], &c1[i]);
  int k;
  for (int i = 0; i < n; i++)
  {
    int a = (a1[i] >= b1[i] && a1[i] >= c1[i]) ? a1[i] : (b1[i] >= c1[i]) ? b1[i] : c1[i];
    int c = (a1[i] <= b1[i] && a1[i] <= c1[i]) ? a1[i] : (b1[i] <= c1[i]) ? b1[i] : c1[i];
    int b = (a1[i] > b1[i]) ? (c1[i] > a1[i] ? a1[i] : (b1[i] > c1[i] ? b1[i] : c1[i])) : (c1[i] > b1[i] ? b1[i] : (a1[i] > c1[i] ? a1[i] : c1[i]));

    if (a >= (b + c))
      count = b + c;
    else
    {
      k = b + c - a;
      k = k / 2 + k % 2;
      b -= k;
      c -= k;
      count += b + c + k;
    }
    printf("%d\n", count);
    count = 0;
  }
  return 0;
}
