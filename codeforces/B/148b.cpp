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
    int vp, vd, t, f, c;
    cin>>vp>>vd>>t>>f>>c;
    if(vp >= vd)
    	cout<<0;
    else
    {
    	double end = c*1.0;
    	int count=0;
    	double dist = (vp*t)*1.0;
    	while(true)
    	{
    		if(dist >= end)
    			break;
    		int g = __gcd(vd, vp);
    		int lcm = (vd*vp)/g;
    		double tmeet = (dist)/((vd*1.0)-(vp*1.0));
    		double currdist = dist+(vp*1.0)*tmeet;
    		if(currdist >= end)
    			break;
    		else
    		{
    			dist = currdist + (currdist/(vd*1.0))*(vp*1.0) + (f*vp*1.0);
    			count++;
    		}
    	}
    	cout<<count;
    }
    return 0;
}