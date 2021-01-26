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
    int n;
    cin>>n;
    vector<pii> coord(n);
    for(int i=0;i<n;i++)
    {
    	cin>>coord[i].ff>>coord[i].ss;
    }
    map<int,ll> fre;
    for(int i=0;i<n;i++)
    	fre[coord[i].ff]++;
    ll ans = 0;
    for(auto x: fre)
    {
    	ans += (x.ss)*(x.ss-1)/2;
    }
    fre.clear();
    for(int i=0;i<n;i++)
    	fre[coord[i].ss]++;
    for(auto x: fre)
    {
    	ans += (x.ss)*(x.ss-1)/2;
    }
    map<pii,ll> rep;
    for(pii x: coord)
    	rep[x]++;
    for(auto x: rep)
    	ans -= (x.ss)*(x.ss-1)/2;
    cout<<ans;
    return 0;
}