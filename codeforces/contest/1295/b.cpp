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
    int t;
    cin>>t;
    while(t--)
    {
    	int n,x;
    	cin>>n>>x;
    	string s;
    	cin>>s;
    	int count=0;
    	vector<int> fre(n);
    	int c0=0,c1=0;
    	for(int i=0;i<n;i++)
    	{
    		if(s[i] == '1')
    			c1++;
    		else
    			c0++;
    		fre[i]=c0-c1;
    	}
    	bool f = false;
    	if(x==0)
    		count++;
    	int toadd = fre[n-1];
    	for(int i=0;i<n;i++)
    	{
    		if(toadd == 0)
    		{
    			if(fre[i] == x)
    				f = true;
    		}
    		else
    		{
    			if(abs(x-fre[i])%abs(toadd) == 0)
    			{
    				if((x-fre[i])/toadd >= 0)
    					count++;
    			}
    		}
    	}
    	if(f)
    		cout<<-1<<endl;
    	else
    		cout<<count<<endl;
    }
    return 0;
}