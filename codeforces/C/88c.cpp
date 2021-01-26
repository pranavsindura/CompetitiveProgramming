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

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
    FASTIO;
    ll a, b;
    cin>>a>>b;
    ll lcm = a*b/gcd(a,b);
    ll dasha = lcm/a, masha = lcm/b;
    if(a > b)
    	dasha++;
    else if(a < b)
    	masha++;
    if(dasha > masha)
    	cout<<"Dasha";
    else if(masha > dasha)
    	cout<<"Masha";
    else
    	cout<<"Equal";
    return 0;
}