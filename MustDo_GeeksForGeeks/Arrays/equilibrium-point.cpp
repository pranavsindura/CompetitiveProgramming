/*
	EQUILIBRIUM POINT
	Equilibrium position in an array is a position such that the sum of
	elements before it is equal to the sum of elements after it.
*/

/*
	Approach 1 - O(n^2)
	Fum sum on left and right w/o prefix
	Approach 2 - O(n)
	Find sum on left and right w/ prefix
*/

ll sum(int i, int j, vector<ll> &arr)
{
    ll s = 0;
    s = arr[j];
    if(i)
        s -= arr[i-1];
    return s;
}

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> arr(n),pre(n);
        for(ll &x: arr)cin>>x;
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
            pre[i] = pre[i-1]+arr[i];
        int ind = -1;
        for(int i=0;i<n;i++)
        {
            ll lsum = sum(0,i,pre) - arr[i];
            ll rsum = sum(i,n-1,pre) - arr[i];
            // cout<<i<<": "<<lsum<<" "<<rsum<<endl;
            if(lsum == rsum)
            {
                ind = i+1;
                break;
            }
        }
        cout<<ind<<endl;
    }
    return 0;
}