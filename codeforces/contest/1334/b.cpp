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
ll sum(int l, int r, vector<ll> &arr)
{
    return (l ? arr[r] - arr[l - 1] : arr[r]);
}

void cp()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(ll &y : arr)
        cin >> y;
    sort(all(arr));
    vector<ll> pre(n);
    pre[0] = arr[0];
    for(int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];
    ll s = x;
    int mi = 0;
   for(int i=n-1;i>=0;i--)
   {
   		int people = n-i;
   		if(sum(i, n-1, pre) >= x*people)
   			mi = people;
   }
   cout<<mi<<endl;
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