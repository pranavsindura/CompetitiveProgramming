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
    int t;
    cin>>t;
    while(t--)
    {
    	int a,b;
    	cin>>a>>b;
    	int r = a%b;
    	if(r==0)
    		cout<<0<<endl;
    	else
    	{
    		int d = (a+b-1)/b;
    		d *= b;
    		cout<<d-a<<endl;
    	}
    }
    return 0;
}