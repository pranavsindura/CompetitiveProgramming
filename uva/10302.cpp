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
ll dp[50005];
void init()
{
	for(ll i=1;i<50005;i++)
		dp[i] = dp[i-1] + i*i*i;
}
int main()
{
    FASTIO;
    int x;
    init();
    while(cin>>x)
    	cout<<dp[x]<<endl;
    return 0;
}