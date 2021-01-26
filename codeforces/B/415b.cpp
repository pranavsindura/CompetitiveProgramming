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
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> arr(n);
    for(ll &x: arr)cin>>x;
    vector<ll> ans;
    for(ll x: arr)
    {
    	ll d = (x*a)/b;
    	d *= b;
    	d = (d+a-1)/a;
    	ans.pb(x-d);
    }
    for(ll x: ans)
    	cout<<x<<" ";
    return 0;
}