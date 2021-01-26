/*
	Minimum Sum partition
	Divide array into two subsets such that the absolute difference
	of the sum of the two subets is minimum
*/
/*
	Approach - DP O(n*sum) space O(n*sum) time
		Modification on Knapsack problem
		We can divide the array into 2 parts such that their sum is close to half of the array sum

		We can find the max sum we achieve upto Sum/2
		The remaining half will be total - dp[n][sum/2]
		The absolute difference will be minimum

*/

void cp()
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 0; i < n; i++)
        cin >> arr[i + 1], sum += arr[i + 1];

    int dp[n + 1][sum + 1];
    clr(dp, 0);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            // make j sum using first i items
            // if i use this item i came from sum j-arr[i]
            // value added is also arr[i]
            if(j >= arr[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
            //also can skip picking
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    int half = sum / 2;
    int half_sum = dp[n][half];
    int rem = sum - half_sum;
    cout << abs(half_sum - rem) << endl;
}