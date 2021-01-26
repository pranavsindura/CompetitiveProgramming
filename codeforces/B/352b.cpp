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

int main()
{
    FASTIO;
    int n,x;
    cin>>n;
    map<int, vector<int>> m;
    for(int i=0;i<n;i++)
    {
    	cin>>x;
    	m[x].push_back(i);
    }
    vector<pair<int,int>> ans;
    for(auto x: m)
    {
    	if(sz(x.second) == 1)
    	{
    		ans.push_back(mp(x.first, 0));
    	}
    	else
    	{
    		int d=x.second[1]-x.second[0];
    		bool same = true;
    		for(int i=0;i<sz(x.second)-1;i++)
	    	{
	    		int curr_d = x.second[i+1]-x.second[i];
	    		if(curr_d != d){
	    			same = false;
	    			break;
	    		}
	    	}
	    	if(same)
	    	{
	    		ans.push_back(mp(x.first, d));
	    	}
    	}
    	
    }
    cout<<sz(ans)<<endl;
    for(auto x: ans)
    	cout<<x.first<<" "<<x.second<<endl;
    return 0;
}