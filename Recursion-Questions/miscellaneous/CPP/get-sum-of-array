int getSum(int arr[], int size)
{

    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    int sum = arr[0] + getSum(arr + 1, size - 1);
    return sum;
}