/*
Question Link:- https://www.codingninjas.com/studio/problems/merge-sort_920442
*/

void merge(vector < int > & arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) 
    {
        second[i] = arr[k++];
    }

    // merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    k = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k] = first[index1++];
        }
        else
        {
            arr[k] = second[index2++];
        }
        k++;
    }

    while (index1 < len1)
    {
        arr[k] = first[index1++];
        k++;
    }
    while (index2 < len2)
    {
        arr[k] = second[index2++];
        k++;
    }

    delete[] first;
    delete[] second;
}

void sol(vector < int > & arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    // sorting left part
    sol(arr, s, mid);

    // sorting right part
    sol(arr, mid + 1, e);

    merge(arr, s, e);
}



void mergeSort(vector < int > & arr, int n) {
    sol(arr, 0, n-1);
}