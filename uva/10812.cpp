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

void solve()
{
	int sum, diff;
	cin>>sum>>diff;
	int a = sum+diff;
	bool ok = true;
	if(a%2 || a<0)
		ok = false;
	a = a/2;
	int b = sum-a;
	if(b<0)
		ok = false;
	if(ok)
		cout<<a<<" "<<b<<endl;
	else
		cout<<"impossible\n";

}

int main()
{
    FASTIO;
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
    	solve();
    }
    return 0;
}