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
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)res = res * x;
        x = x * x;
        y /= 2;
    }
    return res;
}

int main()
{
    FASTIO;
    string s;
    int f = 0;
    while(getline(cin, s))
    {
        vector<ll> a, b;
        ll x;
        stringstream s1(s);
        while(s1 >> x)
            a.pb(x);
        getline(cin, s);
        // cin>>s;
        stringstream s2(s);
        while(s2 >> x)
            b.pb(x);
        reverse(all(a));
        for(int j=0;j<sz(b);j++)
        {
        	ll y = b[j];
        	ll ans=0;
        	for(int i=0;i<sz(a);i++)
        	{
        		ans += a[i] * fpow(y,i);
        	}
        	if(j)
        		cout<<" "<<ans;
        	else
        		cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}