bool linearSearch(int arr[], int size, int key)
{

    if(arr[0]==key){
        return 1;
    }
    if (size==0)
    {
        return 0;
    }
    
    return linearSearch(arr+1, size-1, key);

}