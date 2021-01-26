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
	vector<int> arr(n);
	vector<bool> vis(n, false);
	for(int &x: arr)
		cin>>x;
	bool ok = false;
	for(int d=1;d*d<=n;d++)
	{
		if(n%d == 0)
		{
			int a = d, b = n/d;
			// cout<<"side size: "<<a<<", number of such polygon: "<<b<<endl;
			for(int i=0;i<a;i++)
			{
				int count=0;
				for(int j=0;j<b;j++)
				{
					count += arr[(i+j*a)];
				}
				if(count == b && count > 2)
					ok = true;
				// cout<<i<<": "<<count<<endl;
			}
			for(int i=0;i<b;i++)
			{
				int count=0;
				for(int j=0;j<a;j++)
				{
					count += arr[(i+j*b)];
				}
				if(count == a && count > 2)
					ok = true;
				// cout<<i<<": "<<count<<endl;
			}
		}
	}
	cout<<(ok?"YES":"NO");
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