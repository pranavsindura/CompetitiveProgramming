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
const int MAXN = 2e5 + 5;

int arr[MAXN], t[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = t[2 * v] + t[2 * v + 1];
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
        int tm = (tr + tl) / 2;
        return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

void cp()
{
    int n;
    int tc = 1;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        build(1, 0, n - 1);
        string s;
        if(tc > 1)
            cout << endl;
        cout << "Case " << tc++ << ":\n";
        while(cin >> s && s != "END")
        {
            int u, v;
            cin >> u >> v;
            if(s[0] == 'M')
                cout << query(1, 0, n - 1, u - 1, v - 1) << endl;
            else
                update(1, 0, n - 1, u - 1, v);
        }
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