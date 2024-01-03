bool binarySearch(int arr[], int s, int e, int size, int key)
{

    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    else if (arr[mid] < key)
    {

        return binarySearch(arr, mid + 1, e, size, key);
    }
    else if (arr[mid] > key)
    {
        return binarySearch(arr, s, mid - 1, size, key);
    }
}