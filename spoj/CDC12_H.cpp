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

ll t[4 * MAXN], lazy[4 * MAXN];

void push(int v, int llen, int rlen)
{
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];

    t[v * 2] += lazy[v] * llen;
    t[v * 2 + 1] += lazy[v] * rlen;

    lazy[v] = 0;
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = lazy[v] = 0;
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = lazy[v] = 0;
    }
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) / 2;
        push(v, tm - tl + 1, tr - tm);
        return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void update(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
        t[v] += (r - l + 1), lazy[v]++;
    else
    {
        int tm = (tr + tl) / 2;
        push(v, tm - tl + 1, tr - tm);
        update(v * 2, tl, tm, l, min(r, tm));
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

}

void cp()
{
    int n, q;
    cin >> n >> q;
    build(1, 0, n - 1);
    while(q--)
    {
        string t;
        int u, v;
        cin >> t >> u >> v;
        if(t == "answer")
        {
            cout << query(1, 0, n - 1, u - 1, v - 1) << endl;
        }
        else
        {
            update(1, 0, n - 1, u - 1, v - 1);
            cout << "OK" << endl;
        }
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Scenario #" << i << ":\n";
        cp();
    }
    return 0;
}