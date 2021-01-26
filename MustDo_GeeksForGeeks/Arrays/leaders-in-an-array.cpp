/*
	LEADER IN AN ARRAY
	An element of array is leader if it is greater than or equal to all the elements to its right side.
*/

/*
	Approach 1 - O(n^2)
	check if each element is leader

	Approach 2 - O(n)
	keep track of maximum element from right to left
	if any element is greater than max element it is leader, update maximum
*/

// Approach 2
int main()
{
    FASTIO;
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        vector<int> arr(n);
        for(int &i: arr)cin>>i;
        int mx = INT_MIN;
        vector<int> leader;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i] >= mx)
            {
                leader.push_back(arr[i]);
                mx=arr[i];
            }
        }
        for(int i=sz(leader)-1;i>=0;i--)
            cout<<leader[i]<<" ";
        cout<<endl;
    }
    return 0;
}