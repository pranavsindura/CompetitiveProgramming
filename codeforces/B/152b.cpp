#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define watch(x) {cout<<#x<<": "<<x<<endl;}
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

bool check(ll i, ll j, ll n, ll m)
{
    if(i > 0 && i <= n && j > 0 && j <= m)
        return true;
    else
        return false;
}

int main()
{
    FASTIO;
    ll n, m, a, b, k, x, y, steps = 0;
    cin >> n >> m >> a >> b >> k;
    vector<pair<ll, ll>> list(k);
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        list[i] = mp(x, y);
    }
    for(int i = 0; i < k; i++)
    {
        ll diffx = 0, stepx = 0, diffy = 0, stepy = 0, sx = 1, sy = 1;
        x = list[i].first, y = list[i].second;
        ll lo = 1, hi = INT_MAX;
        ll currstep=0;
        while(lo<=hi)
        {
        	ll mid = (hi+lo)/2;
        	// cout<<"trying: "<< a+x*mid <<", "<< b+y*mid<<endl;
        	// watch(lo);
        	// watch(hi);
        	// watch(mid);
        	if(check(a+x*mid, b+y*mid,n,m))
        		currstep=mid, lo=mid+1;
        	else
        		hi = mid-1;
        }
        // cout<<currstep<<endl;
        steps += currstep;
        a += currstep*x;
        b += currstep*y;
        // cout<<"at: "<<a<<" "<<b<<endl;
    }
    cout << steps;
    return 0;
}