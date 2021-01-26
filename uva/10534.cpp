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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e4 + 5;
/*
Find LIS from both directions with segtree
then for each position take min of the LIS ending at it
from both directions and make a wavio seq using it
*/

int t[4 * MAXN];
void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = 0;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}
void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
    {
        t[v] = max(t[v], val);
    }
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

int get(int v, int tl, int tr, int pos)
{
    if(tl == tr)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        if(tm <= pos)
            return get(v << 1, tl, tm, pos);
        else
            return get(v << 1 | 1, tm + 1, tr, pos);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, min(r, tm));
        int right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return max(left, right);
    }
}
void cp()
{
    int n;
    while(cin >> n)
    {
        vector<int> arr(n);
        map<int, int> comp;
        for(int &x : arr)
            cin >> x, comp[x];
        int N = 0;
        for(auto &x : comp)
            x.ss = N++;
        for(int &x : arr)
            x = comp[x];

        vector<int> dpleft(n), dpright(n);

        build(1, 0, N);
        for(int i = 0; i < n; i++)
        {
            int me = query(1, 0, N, 0, arr[i] - 1);
            dpleft[i] = me + 1;
            update(1, 0, N, arr[i], me + 1);
        }

        build(1, 0, N);
        for(int i = n - 1; i >= 0; i--)
        {
            int me = query(1, 0, N, 0, arr[i] - 1);
            dpright[i] = me + 1;
            update(1, 0, N, arr[i], me + 1);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int len = min(dpleft[i], dpright[i]) * 2 - 1;
            ans = max(ans, len);
        }
        cout << ans << endl;
    }
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