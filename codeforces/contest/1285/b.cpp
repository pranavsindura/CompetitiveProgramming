#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

ll maxCrossSum(vector<ll> &arr, int l, int m, int r)
{
	ll leftSum=INT_MIN,rightSum=INT_MIN, currSum=0;
	for(int i=m;i>=l;i--)
	{
		currSum+=arr[i];
		leftSum = max(leftSum, currSum);
	}
	currSum=0;
	for(int i=m+1;i<=r;i++)
	{
		currSum+=arr[i];
		rightSum = max(rightSum, currSum);
	}
	return leftSum+rightSum;
}

ll maxSum(vector<ll> &arr, int l, int r)
{
	// cout<<l<<" "<<r<<endl;
	if(l==r)
		return arr[l];
	int m = (l+r)/2;
	ll ans = max({maxSum(arr, l, m), maxSum(arr, m+1, r),maxCrossSum(arr, l, m, r)});
	// cout<<l<<" "<<r<<": "<<ans<<endl;
	return ans;
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
    	vector<ll> arr(n);
    	ll total=0;
    	for(int i=0;i<n;i++)
    		cin>>arr[i];

    	for(int i=0;i<n;i++)
    		total+=arr[i];
    	ll m = max(maxSum(arr, 0, n-2),maxSum(arr, 1, n-1));
    	// cout<<m<<endl;
    	if(total > m)
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    }
    return 0;
}