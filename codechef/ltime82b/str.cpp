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

ll fpow(ll x, ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y&1)
			res = (res%mod * x%mod)%mod;
		x = (x%mod * x%mod)%mod;
		y = y/2;
	}
	return res%mod;
}

ll inv(ll x)
{
	return fpow(x, mod-2);
}

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
    	int d;
    	cin>>d;
    }
    return 0;
}