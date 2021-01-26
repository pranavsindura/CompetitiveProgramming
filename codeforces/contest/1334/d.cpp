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
vector<ll> arr(100005, 0);

int solve(ll i, ll n)
{
	if(i > arr[n-1])
		return 1;
	auto it = lower_bound(arr.begin()+1, arr.begin()+n, i);
	int ind = it - arr.begin();
	ll diff = i - arr[ind-1];
	if(diff%2 == 1)
		return ind;
	else
		return ind + (diff)/2;
}

void cp()
{
    ll n, l, r;
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
    {
    	arr[i] = arr[i-1] + 2LL*(n-i);
    }
    // cout<<arr[3]<<endl;
    for(ll i=l;i<=r;i++)
    {
    	cout<<solve(i, n)<<" ";
    }
    cout<<endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}