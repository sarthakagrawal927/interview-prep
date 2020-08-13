
#include <stdio.h>

// Function to return the only odd occurring element
int findOdd(int arr[], int n)
{
    int res = 0, i;
    for (i = 0; i < n; i++)
    {
        res ^= arr[i];
        printf("%d ", res);
    }
    return res;
}
//1001 XOR 1010 gives 0111 , odd 1 gives 1 so when to same numbers come they cancel each other out

int main(void)
{
    int arr[] ={ 12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The odd occurring element is %d ",
        findOdd(arr, n));
    return 0;
}
