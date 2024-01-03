/*
Question Link:- https://www.codingninjas.com/studio/problems/binary-search_972
*/


int binarySearch(const vector<int>& arr, int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else // arr[mid] > key
    {
        return binarySearch(arr, s, mid - 1, key);
    }
}

int search(const vector<int>& nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}
