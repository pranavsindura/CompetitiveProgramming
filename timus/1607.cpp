#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int t=0;
    while(true)
    {
    	if(a+b*t >= c-d*t)
    	{
    		cout<<a+b*t;
    		break;
    	}
    	if(c-d*t<=a+b*(t+1))
    	{
    		cout<<c-d*t;
    		break;
    	}
    	t++;
    }
    return 0;
}