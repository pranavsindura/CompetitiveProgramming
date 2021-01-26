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
    	string s;
    	cin>>s;
    	int ind;
    	bool one = false;
    	for(int i=0;i<ln(s);i++)
    	{
    		if(s[i] == '1')
    		{
    			one = true;
    			ind = i;
    			break;
    		}
    	}
    	if(one)
    	{
    		int last = ind;
    		int ans=0, zero=0;
    		for(int i=ind+1;i<ln(s);i++)
    		{
    			if(s[i] == '0')
    			{
    				zero++;
    			}
    			else
    			{
    				ans += zero;
    				last = i;
    				zero=0;
    			}
    		}
    		cout<<ans<<endl;
    	}
    	else
    	{
    		cout<<0<<endl;
    	}
    }
    return 0;
}