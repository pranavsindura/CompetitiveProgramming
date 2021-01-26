/*
	Count Distinct numbers in all subarrays of size K
*/
/*
	Approach 1 - Brute Force Hashing of every Sub Array of size K O(nK)
	Approach 2 - Two pointers
		At each point only ends of the subarray are manipulated
		Add frequency of right pointer
		Remove frequency of left pointer
*/
vector <int> countDistinct (int A[], int n, int k)
{
    int freq[100005] = {0};
    int distinct = 0;
    for(int i = 0; i < k; i++)
    {
        if(freq[A[i]] == 0)
            distinct++;
        freq[A[i]]++;
    }
    vector<int> res;
    res.push_back(distinct);
    for(int i = k; i < n; i++)
    {
        if(freq[A[i]] == 0)
            distinct++;
        freq[A[i]]++;

        freq[A[i - k]]--;
        if(freq[A[i - k]] == 0)
            distinct--;
        res.push_back(distinct);
    }
    return res;
}