#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
ll binsmall(int start, int end, ll x, vector<ll> &arr)
{
	int lo = start, hi = end;
	ll ans = -1;
	while(lo<=hi)
	{
		int mid = lo + (hi-lo)/2;
		if(arr[mid] < x)
			ans = arr[mid], lo = mid+1;
		else
			hi = mid-1;
	}
	return ans;
}
int main()
{
    FASTIO;
    int n, q;
    ll h;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    cin>>q;
    while(q--)
    {
    	cin>>h;
    	ll l = binsmall(0, n-1, h, arr);
    	if(l == -1)
    		cout<<"X ";
    	else
    	{
    		cout<<l<<" ";
    	}
    	vector<ll>::iterator g = upper_bound(all(arr), h);
    	if(g == arr.end())
    		cout<<"X\n";
    	else
    		cout<<*g<<endl;
    }
    return 0;
}