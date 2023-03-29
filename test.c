#include <stdio.h>

int LIS(int arr[], int n)
{
    int *lis;
    int max_lis = 0;
    int i = 0;
    int j = 0;
    
    // Initialize LIS values for all indexes
    lis = malloc(n * sizeof(int));
    while(i < n)
       lis[i++] = 1;
    // Compute LIS values in bottom-up manner
    i = 1;
    while(i < n)
    {
      j = 0;
      while( j < i)
      {
         if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
            j++;
      }
      i++;
    }
    // for(int i = 1; i < n; i++)
    // {
    //     for(int j = 0; j < i; j++)
    //     {
    //         if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
    //         {
    //             lis[i] = lis[j] + 1;
    //         }
    //     }
    // }
    
    // Pick the maximum of all LIS values
    // for(int i = 0; i < n; i++)
    // {
    //     if(lis[i] > max_lis)
    //     {
    //         max_lis = lis[i];
    //     }
    // }
    
    return max_lis;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int lis = LIS(arr, n);
    
    printf("Length of LIS is %d", lis);
    
    return 0;
}