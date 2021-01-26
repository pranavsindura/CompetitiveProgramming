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
const int MAXN = 1e5 + 5;
int n, m, k;
int arr[MAXN][5], t[4 * MAXN][5];

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        for(int i = 0; i < m; i++)
            t[v][i] = arr[tl][i];
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        for(int i = 0; i < m; i++)
            t[v][i] = max(t[v << 1][i], t[v << 1 | 1][i]);
    }
}

int query(int v, int tl, int tr, int l, int r, int idx)
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return t[v][idx];
    else
    {
        int tm = (tl + tr) >> 1;
        return max(query(v << 1, tl, tm, l, min(r, tm), idx), query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, idx));
    }
}

void cp()
{
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    build(1, 0, n - 1);

    int lo = 1, hi = n;
    vector<int> ans(m), res(m);
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        bool can = false;
        vector<int> here;

        for(int i = 0; i + mid - 1 < n; i++)
        {
            int total = 0;

            for(int j = 0; j < m; j++)
                res[j] = query(1, 0, n - 1, i, i + mid - 1, j), total += res[j];

            if(total <= k)
            {
                can = true, here = res;
                break;
            }
        }

        if(can)
            ans = here, lo = mid + 1;
        else
            hi = mid - 1;
    }

    for(int x : ans)
        cout << x << " ";
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