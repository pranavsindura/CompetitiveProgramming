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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n, m;
    ll k;

    cin >> n >> m;

    vector<ll> a(n), b(m);

    for(ll &x : a)
        cin >> x;
    for(ll &x : b)
        cin >> x;

    cin >> k;

    for(int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for(int i = 1; i < m; i++)
        b[i] += b[i - 1];

    vector<ll> min_sum_a(n + 1, LLONG_MAX), min_sum_b(m + 1, LLONG_MAX);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j + i - 1 < n; j++)
        {
            //[j, j+i-1]
            ll sum = a[j + i - 1] - (j ? a[j - 1] : 0);
            min_sum_a[i] = min(min_sum_a[i], sum);
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j + i - 1 < m; j++)
        {
            //[j, j+i-1]
            ll sum = b[j + i - 1] - (j ? b[j - 1] : 0);
            min_sum_b[i] = min(min_sum_b[i], sum);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(min_sum_a[i] * min_sum_b[j] <= k)
                ans = max(ans, i * j);

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}