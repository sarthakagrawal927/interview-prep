#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
  int n,count=0;
  scanf("%lld\n",&n );
  long long int A[n],B[n];
  for(int j=0; j<n; j++)
    scanf("%lld %lld",&A[j],&B[j] );
  for(int j=0; j<n; j++)
  {
    count=(int)(log10(B[j]));
    if((int)log10(B[j]+1)==(count+1)) count+=1;
    printf("%lld\n",count*A[j]);
  }
  return 0;
}
