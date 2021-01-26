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

void cp()
{
	int n;
	cin>>n;
	vector<int> h;
	for(int i=2;i<=n;i++)
	{
		int x = i;
		map<int,int> fac;
		for(int j=2;j*j<=x;j++)
		{
			while(x%j == 0)
				fac[j]++, x/=j;
		}
		if(x>1)
			fac[x]++;
		if(sz(fac) == 1)
		{
			h.pb(i);
		}
	}
	cout<<sz(h);nl;
	for(int x: h)
		cout<<x<<" ";
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