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
    int a,b;
    cin>>a>>b;
    while(!(a==1 && b==1))
    {
    	pii l,r,x=mp(1,1);
    	l = mp(0,1);
    	r = mp(1,0);
    	string s;
    	while(true)
    	{
    		pii mid = mp(l.first+r.first, l.second+r.second);
    		if(mid == mp(a,b))
    			break;
    		double m = (mid.first*1.0)/(mid.second*1.0);
    		double n = (a*1.0)/(b*1.0);
    		if(n-m > eps)
    		{
    			l = mid;
    			s += "R";
    		}
    		else
    		{
    			r = mid;
    			s += "L";
    		}

    	}
    	cout<<s<<endl;
    	cin>>a>>b;
    }
    return 0;
}