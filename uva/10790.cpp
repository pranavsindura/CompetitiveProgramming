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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

ll cp(ll n, ll m)
{
    ll ans = 0;
    ll sum1 = (n - 1) * n / 2;
    ll sum2 = (m - 1) * m / 2;
    return sum1 * sum2;
}

int main()
{
    FASTIO;
    int c = 1;
    ll n, m;
    while(cin >> n >> m && (n || m))
    {
        ll sum1 = (n - 1) * n / 2;
        ll sum2 = (m - 1) * m / 2;
        cout << "Case " << c++ << ": " << sum1 *sum2 << endl;
    }
    return 0;
}