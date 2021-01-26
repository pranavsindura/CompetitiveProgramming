#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    ll max_bit[32], min_bit[32], po2[32];
    po2[0] = 1;

    for(int i = 1; i < 32; i++)
        po2[i] = po2[i - 1] * 2;

    for(int i = 0; i < 32; i++)
        max_bit[i] = 0, min_bit[i] = INT_MAX;

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        ll x = arr[i];
        int cnt = 0;
        while(x)
            cnt++, x /= 2;
        max_bit[cnt] = max(max_bit[cnt], arr[i]);
        min_bit[cnt] = min(min_bit[cnt], arr[i]);
    }

    for(int i = 1; i < 32; i++)
    {
        for(int j = 1; j < 32; j++)
        {
            ll x = max_bit[j];
            ll y = min_bit[i];
            if(x == 0 || y == INT_MAX)
                continue;
            ll res = x * (po2[i] - 1) - y * (po2[j] - 1);
            ans = max(ans, res);
        }
    }

    cout << ans << endl;

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