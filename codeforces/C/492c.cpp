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
    int n,r;
    ll avg;
    cin>>n>>r>>avg;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++)
    {
      cin>>a[i].ff>>a[i].ss;
    }
    ll now=0;
    for(int i=0;i<n;i++)
    {
      now += a[i].ff;
    }
    if(now >= avg*n)
    {
      cout<<0;
      return 0;
    }
    sort(all(a),[](auto a, auto b){
      return a.ss<b.ss;
    });
    //cout<<now<<" "<<avg*n<<endl;
    ll rem = avg*n-now;
    ll ans = 0;
    for(int i=0;i<n && rem;i++)
    {
      ll diff = r-a[i].ff;
      ll sub = min(diff, rem);
      //cout<<i<<" "<<rem;
      rem -= sub;
      ans += sub*a[i].ss;
    }
    cout<<ans;
    return 0;
}