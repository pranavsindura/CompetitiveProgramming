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
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define nl cout<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
	int n;
	cin>>n;
	vector<ll> a(n), b(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	ll bullet = a[0];
	ll damage = b[0];
	for(int i=1;i<n;i++)
	{
		ll health = max(0LL, a[i] - b[i-1]);
		bullet += health;
	}
	ll min_bullet = bullet;
	for(int i=1;i<n;i++)
	{
		ll cur_bullet = bullet - a[i-1] - max(0LL, a[i]-b[i-1]) + a[i] + max(0LL, a[i-1] - b[(i-2+n)%n]);
		min_bullet = min(min_bullet, cur_bullet);
		bullet = cur_bullet;
	}
	cout<<min_bullet<<endl;
}

int main()
{
    FASTIO;
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
    	cp();
    }
    return 0;
}