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
const double PI = acos(-1.0);
using namespace std;

vector<vector<int>> divs(500005);
vector<int> fre(500005, 0);
void cp()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			divs[j].pb(i);
		}
	}
	vector<int> num;
	for(int i=1;i<=n;i++)
		num.pb(i);
	sort(all(num),[](int a, int b){
		return divs[a][sz(divs[a]) - 2] < divs[b][sz(divs[b]) - 2];
	});
	vector<int> ans;
	int mx = 1;
	for(int i=0;i<n-1;i++)
	{
		for(int x: divs[num[i]])
		{
			fre[x]++;
			if(fre[x] >= 2)
				mx = max(mx, x);
		}
		cout<<mx<<" ";
	}
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