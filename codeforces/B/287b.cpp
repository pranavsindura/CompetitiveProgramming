#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
ll sum(ll a)
{
	return a*(a+1)/2;
}
ll sumrange(ll a, ll b)
{
	return sum(b) - sum(a-1);
}
ll bin(ll n, ll k)
{
	ll m = k-1;
	ll lo = 1, hi = k-1;
	while(lo<=hi)
	{
		ll mid = lo + (hi-lo)/2;
		if(sumrange(mid, k-1) <= n-1)
			m = mid, hi = mid-1;
		else
			lo = mid+1;
	}
	return m;
}
int main()
{
    FASTIO;
    ll n, k;
    cin>>n>>k;
    if(n == 1)
    {
    	cout<<0;
    	return 0;
    }
    if(k>=n)
    	cout<<1;
    else if(n - 1 > k*(k-1)/2)
    	cout << -1;
    else
    {
    	ll a = bin(n, k);
    	if(sumrange(a, k-1) == n-1)
    		cout<<k-a;
    	else
    		cout<<k-a+1;
    }
    return 0;
}