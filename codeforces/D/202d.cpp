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
const int MAXN = 1e3 + 5;
ll arr[MAXN][MAXN];
ll si[MAXN], sj[MAXN];
void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            si[i] += arr[i][j], sj[j] += arr[i][j];

    ll cost = 0;

    int minx = 0;
    ll mn = LLONG_MAX;
    for(int x = 0; x <= n; x++)
    {
        int xdash = 4 * x;
        ll val = 0;
        for(int i = 0; i < n; i++)
        {
            int h = (i * 4 + (i + 1) * 4) / 2;
            val += si[i] * (xdash - h) * 1LL * (xdash - h);
        }
        if(val < mn)
            mn = val, minx = x;
    }
    cost += mn;

    int miny = 0;
    mn = LLONG_MAX;
    for(int y = 0; y <= m; y++)
    {
        int ydash = 4 * y;
        ll val = 0;
        for(int j = 0; j < m; j++)
        {
            int k = (j * 4 + (j + 1) * 4) / 2;
            val += sj[j] * (ydash - k) * 1LL * (ydash - k);
        }
        if(val < mn)
            mn = val, miny = y;
    }
    cost += mn;
    
    cout << cost << endl;
    cout << minx << " " << miny;
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