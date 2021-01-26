/*
	Merge Sort
*/

/*
	Standard Merge Sort implementation
	Only need to implement merge function
*/

/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int k = 0;
    for(int i = l; i <= m; i++)
        L[k] = arr[i], k++;
    k = 0;
    for(int i = m + 1; i <= r; i++)
        R[k] = arr[i], k++;
    int i = 0, j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k] = L[i], i++;
        else
            arr[k] = R[j], j++;
        k++;
    }
    while(i < n1)
        arr[k] = L[i], i++, k++;
    while(j < n2)
        arr[k] = R[j], j++, k++;
}