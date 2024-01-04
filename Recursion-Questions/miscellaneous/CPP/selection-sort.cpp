void selectionSort(int arr[], int n, int currentIndex = 0){
    if (n==0 || n==1 || currentIndex == n - 1)
    {
        return;
    }
    int minIndex = currentIndex;

    for (int i = currentIndex+1; i < n; i++)
    {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }        
    }

    // Swap the found minimum element with the first element
    swap(arr[currentIndex], arr[minIndex]);

    // Recursively sort the rest of the array
    selectionSort(arr, n, currentIndex + 1);
    
}