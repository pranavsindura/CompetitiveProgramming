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

int main()
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
    	int s;
    	cin>>s;
    	ll spend=0;
    	while(s)
    	{
    		int x = s/10;
    		if(x != 0)
    			spend += x*10;
    		else
    		{
    			spend += s;
    			break;
    		}
    		s = s%10;
    		s += x;
    	}
    	cout<<spend<<endl;
    }
    return 0;
}