/*
	Find maximum Length chain that can be formed with non overlapping ranges
	Two ranges [a, b] and [c, d] can be joined only if b < c
*/
/*
	Approach - DP
		Kind of Modified Longest Increasing Subsequence
		The ranges are in arbitrary order, we can attach any to any as long as they agree
		So we cannot change [l, r] but we can sort according to our need
		We sort the ranges first, then we use LIS logic to find max length chain

		O(nlogn) + O(n^2) => O(n^2)
*/

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    int LIS[n+1];
    memset(LIS, 0, sizeof LIS);
    
    sort(p, p+n,[&](val a, val b){
        pair<int,int> x = {a.first, a.second};
        pair<int,int> y = {b.first, b.second};
        return x < y; 
    });
    // MAX LIS ending at i
    for(int i=0;i<n;i++)
    {
        LIS[i] = 1;
        for(int j=0;j<i;j++)
        {
            // Can attach LIS[j] with i
            if(p[j].second < p[i].first)
            {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
    }
    return *max_element(LIS, LIS+n);
}