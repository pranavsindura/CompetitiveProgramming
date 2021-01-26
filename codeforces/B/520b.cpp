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

int main()
{
    FASTIO;
    ll n, m;
    cin>>n>>m;
    queue<pair<ll,ll>> q;
    q.push(mp(n,0));
    bool ok = true;
    bool vis[100005];
    memset(vis, false, sizeof(vis));
    while(!q.empty() || ok)
    {
    	pair<ll,ll> f = q.front();
    	vis[f.first]=true;
    	q.pop();
    	if(f.first==m)
    	{
    		cout<<f.second;
    		return 0;
    	}
    	else if(f.first < m && f.first>0)
    	{
    		if(!vis[2*f.first])
    			q.push(mp(2*f.first, f.second+1));
    		if(!vis[f.first-1])
    			q.push(mp(f.first-1, f.second+1));
    	}
    	else if(f.first > m)
    	{
    		if(!vis[f.first-1])
    			q.push(mp(f.first-1, f.second+1));
    	}
    }
    return 0;
}