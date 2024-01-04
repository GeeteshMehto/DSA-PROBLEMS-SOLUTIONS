void bubbleSort(int arr[], int n){
    if (n==0 || n==1)
    {
        return;
    }
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i]>arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
        
    }
    return bubbleSort(arr, n-1);
      
    
}