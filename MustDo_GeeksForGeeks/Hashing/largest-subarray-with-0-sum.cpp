/*
	Find Length of largest subarrray with 0 sum
*/
/*
	Approach 1 - Store the first occurence of each prefix sum
		Use the fact that target sum can be broken into 2 prefix sums
		Since target is zero, this means that when same sum repeatsm subarray with zero sum is found
*/
int maxLen(int A[], int n)
{
    int mx = 0;
    map<int, int> sum_idx;
    sum_idx[0] = -1;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += A[i];
        if(sum_idx.find(sum) != end(sum_idx))
        {
            mx = max(mx, i - sum_idx[sum]);
        }
        else
            sum_idx[sum] = i;
    }
    return mx;
}
