int *LIS(int arr[], int n, int *len)
{
    int lis[n];
    int prev[n];
    int max_lis = 0, max_lis_index = 0;
    
    // Initialize LIS and prev arrays
    for(int i = 0; i < n; i++)
    {
        lis[i] = 1;
        prev[i] = -1;
    }
    
    // Compute LIS values in bottom-up manner
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
        
        // Update max_lis and max_lis_index
        if(lis[i] > max_lis)
        {
            max_lis = lis[i];
            max_lis_index = i;
        }
    }
    
    // Construct LIS array
    int *result = malloc(max_lis * sizeof(int));
    int current_index = max_lis - 1;
    int current_value = arr[max_lis_index];
    
    while(current_index >= 0)
    {
        result[current_index] = current_value;
        current_index--;
        current_value = arr[prev[max_lis_index]];
        max_lis_index = prev[max_lis_index];
    }
    
    // Set length of LIS
    *len = max_lis;
    
    return result;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int len;
    int *lis = LIS(arr, n, &len);
    
    printf("Length of LIS is %d\n", len);
    printf("LIS is ");
    
    for(int i = 0; i < len; i++)
    {
        printf("%d ", lis[i]);
    }
    
    free(lis);
    
    return 0;
}
