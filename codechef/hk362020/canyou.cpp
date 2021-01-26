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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int sum(int l, int r, int bit, int prefix[][35])
{
	int ans = prefix[r][bit];
	if(l)
		ans -= prefix[l-1][bit];
	return ans;
}

int main()
{
    FASTIO;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &i: arr)
    	cin>>i;
    int prefix[n][35];
    for(int i=0;i<35;i++)
    {
    	prefix[0][i] = ((arr[0]>>i)&1);
    }
    for(int j=0;j<35;j++)
    {
    	for(int i=1;i<n;i++)
    	{
    		prefix[i][j] = prefix[i-1][j] + ((arr[i]>>j)&1);
    	}
    }
    int q;
    cin>>q;
    while(q--)
    {
    	int l,r,k;
    	cin>>l>>r>>k;
    	l--,r--;
    	bool found = false;
    	for(int i=0;i<35;i++)
    	{
    		if(sum(l,r,i,prefix) >= k)
    			found = true;
    	}
    	if(found)
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    }
    return 0;
}