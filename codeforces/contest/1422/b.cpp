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
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for(auto &v : arr)
        for(ll &x : v)
            cin >> x;

    ll cost = 0;
    for(int i = 0; i < n / 2; i++)
    {
        for(int j = 0; j < m / 2; j++)
        {
            ll a = arr[i][j], b = arr[n - i - 1][j], c = arr[i][m - j - 1], d = arr[n - i - 1][m - j - 1];
            ll me = LLONG_MAX;
            me = min(me, abs(a - b) + abs(a - c) + abs(a - d));
            me = min(me, abs(b - a) + abs(b - c) + abs(b - d));
            me = min(me, abs(c - a) + abs(c - b) + abs(c - d));
            me = min(me, abs(d - a) + abs(d - b) + abs(d - c));
            cost += me;
        }

        if(m & 1)
        {
            ll a = arr[i][m / 2], b = arr[n - i - 1][m / 2];
            ll me = LLONG_MAX;
            me = min(me, abs(a - b));
            cost += me;
        }
    }

    if(n & 1)
    {
        for(int j = 0; j < m / 2; j++)
        {
            ll a = arr[n / 2][j], b = arr[n / 2][m - j - 1];
            ll me = LLONG_MAX;
            me = min(me, abs(a - b));
            cost += me;
        }
    }

    cout << cost << endl;
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