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
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define nl cout<<endl;
const double PI = acos(-1.0);
using namespace std;

ll fpow(ll x, ll y, ll m)
{
	ll res=1;
	while(y)
	{
		if(y&1)
			res = (res%m*x%m)%m;
		x = (x%m*x%m)%m;
		y = y/2;
	}
	return res;
}

void cp()
{
	ll n,m;
	cin>>n>>m;
	ll ans = fpow(3, n, m);
	ans = (ans + m - 1)%m;
	cout<<ans;
}

int main()
{
    FASTIO;
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
    	cp();
    }
    return 0;
}