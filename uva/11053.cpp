#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

ll f(ll a, ll b, ll x, ll n)
{
	return (((a%n*x%n)%n*x%n)%n + b%n)%n;
}

int main()
{
    FASTIO;
    ll n,a,b;
    cin>>n;
    while(n)
    {
    	cin>>a>>b;

    	ll x=0;
    	map<ll,int> cnt;
    	while(cnt[f(a,b,x,n)] < 3)
    	{
    		cnt[f(a,b,x,n)]++;
    		x = f(a,b,x,n);
    	}
    	int dead=0;
    	for(auto it: cnt)
    	{
    		if(it.ss >= 2)
    			dead++;
    	}
    	cout<<n-dead<<endl;
    	cin>>n;
    }
    return 0;
}