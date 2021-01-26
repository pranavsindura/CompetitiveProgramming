#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
    	string p, h;
    	cin>>p>>h;
    	map<char,int> m;
    	for(char x: p)
    		m[x]++;
    	bool ans=false;
    	for(int i=0;i<h.length();i++)
    	{
    		map<char,int> m2;
    		for(int j=0;j<p.length();j++)
    		{
    			m2[h[i+j]]++;
    		}
    		bool all=true;
    		for(auto x: m)
    		{
    			if(x.second != m2[x.first])
    				all=false;
    		}
    		if(all)
    		{
    			ans = true;
    			break;
    		}
    	}
    	if(ans)
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    }
    return 0;
}