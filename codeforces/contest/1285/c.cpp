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
vector<pair<ll,ll>> f;

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}
int main()
{
    FASTIO;
    ll x;
    cin >> x;
    
    f.push_back(mp(1, x));
    for(ll i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
        	ll g = gcd(i, x/i);
        	if(g == 1)
				f.push_back(mp(i,x/i));
        }
    }
    ll mi = LLONG_MAX;
    pair<ll,ll> ans;
    for(int i=0;i<sz(f);i++)
    {
    	if(max(f[i].first, f[i].second) <  mi)
    	{
    		ans = f[i];
    		mi = max(f[i].first, f[i].second);
    	}
    }
    cout<<ans.first<<" "<<ans.second;
    return 0;
}