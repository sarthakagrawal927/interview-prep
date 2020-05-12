#include <stdio.h>
int main()
{
    int t;
    scanf("%d\n",&t);
    int a[t];
    for(int k=0; k<t; k++)
    {
      int type,basket;
      a[k]=99999999;
      scanf("%d %d",&basket,&type);
      int fruittype[basket], price[basket];
      int arr[50]={0};
      int arr1[50]={0};

      for(int i=0; i< basket; i++)
        scanf("%d",&fruittype[i]);

      for(int i=0; i< basket; i++)
          scanf("%d",&price[i]);

      for(int i = 0; i< basket; i++){
        arr1[fruittype[i]-1] = 1;
        arr[fruittype[i]-1]+=price[i];
      }

      for(int i=0; i< type; i++)
        if(arr[i] < a[k] && arr1[i]!=0)
            a[k] = arr[i];
    }
    for(int k=0; k<t; k++) printf("%d\n",a[k]);
    return 0;
}
