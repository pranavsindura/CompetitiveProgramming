#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

ll fpow(ll a, ll b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	if(b&1)
		return a * fpow(a*a, b/2);
	else
		return fpow(a*a, b/2);
}
ll value(ll v, ll k)
{
	ll x = v/k;
	ll sum = v;
	while(x > 0)
	{
		sum += x;
		x/=k;
	}
	return sum;
}
int main()
{
    FASTIO;
    ll n, k;
    cin>>n>>k;
    ll lo = 1, hi = n;
    ll v = n;
    while(lo<=hi)
    {
    	ll mid = lo + (hi-lo)/2;
    	ll a = value(mid, k);
    	if(a >= n)
    		v = mid, hi = mid-1;
    	else
    		lo = mid+1;
    }
    cout<<v;
    return 0;
}