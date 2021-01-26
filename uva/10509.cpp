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
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    double n;
    cin>>n;
    while(n > eps)
    {
    	int lo=1, hi=200;
    	double a;
    	while(lo <= hi)
    	{
    		int mid = (lo+hi)/2;
    		if(mid*mid*mid*1.0 <= n)
    			a = mid, lo = mid+1;
    		else
    			hi = mid-1;

    	}
    	double dx = (n-a*a*a)/(3.0*a*a);
    	a += dx;
    	cout<<fixed<<setprecision(4)<<a<<endl;
    	cin>>n;
    }
    return 0;
}