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
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define nl cout<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
	int n;
	cin>>n;
	vector<int> p(n+1),c(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>c[i];
	}
	p[0] = 0, c[0] = 0;
	bool ok = true;
	for(int i=1;i<=n;i++)
	{
		int dp = p[i] - p[i-1];
		int dc = c[i] - c[i-1];
		if(dc > dp || dp < 0 || dc < 0 || p[i] < c[i])
			ok = false;
	}
	cout<<(ok?"YES\n":"NO\n");
}

int main()
{
    FASTIO;
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
    	cp();
    }
    return 0;
}