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

bool check(pii a, pii b, int t)
{
	b.first += t;
	b.second += t;
	if(a.first > b.second || b.first > a.second)
		return false;
	else
		return true;
}

int main()
{
    FASTIO;
    int p,q,l,r,x,y;
    cin>>p>>q>>l>>r;
    vector<pii> a,b;
    for(int i=0;i<p;i++)
    {
    	cin>>x>>y;
    	a.push_back(mp(x,y));
    }
    for(int i=0;i<q;i++)
    {
    	cin>>x>>y;
    	b.push_back(mp(x,y));
    }
    int count = 0;
    for(int i=l;i<=r;i++)
    {
    	bool f = false;
    	for(int j=0;j<sz(a);j++)
    	{
    		for(int k=0;k<sz(b);k++)
    		{
    			if(check(a[j], b[k], i))
    			{
    				// count++;
    				f = true;
    				break;
    			}
    		}
    		if(f)
    			break;
    	}
    	if(f)
    		count++;
    }
    cout<<count;
    return 0;
}
