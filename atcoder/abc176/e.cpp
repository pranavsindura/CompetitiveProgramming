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
const int MAXN = 3e5 + 5;

vector<pi> targets;
vector<vector<int>> row(MAXN), col(MAXN);

int row_cnt[MAXN], col_cnt[MAXN];
int rt[4 * MAXN], ct[4 * MAXN];

void build(int v, int tl, int tr, int arr[], int t[])
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr, t);
        build(v << 1 | 1, tm + 1, tr, arr, t);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int tl, int tr, int pos, int add, int t[])
{
    if(tl == tr)
        t[v] += add;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, add, t);
        else
            update(v << 1 | 1, tm + 1, tr, pos, add, t);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        targets.pb({u, v});
        row[u].pb(i);
        col[v].pb(i);
        row_cnt[u]++;
        col_cnt[v]++;
    }

    build(1, 0, n - 1, row_cnt, rt);
    build(1, 0, m - 1, col_cnt, ct);

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        // take the ith row
        int me = row_cnt[i];
        // remove all targets in row i
        for(int x : row[i])
        {
            int c = targets[x].ss;
            // remove 1 from this col
            update(1, 0, m - 1, c, -1, ct);
        }
        // take max
        int best = ct[1];
        me += best;
        ans = max(ans, me);
        // add the targets back
        for(int x : row[i])
        {
            int c = targets[x].ss;
            // add 1 to this col
            update(1, 0, m - 1, c, 1, ct);
        }
    }

    for(int i = 0; i < m; i++)
    {
        // take the ith col
        int me = col_cnt[i];
        // remove all targets in col i
        for(int x : col[i])
        {
            int r = targets[x].ff;
            // remove 1 from this row
            update(1, 0, n - 1, r, -1, rt);
        }
        // take max
        int best = rt[1];
        me += best;
        ans = max(ans, me);
        // add the targets back
        for(int x : col[i])
        {
            int r = targets[x].ff;
            // add 1 to this row
            update(1, 0, n - 1, r, 1, rt);
        }
    }
    cout << ans;
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