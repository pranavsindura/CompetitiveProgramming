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
const ll inf = 1e15;
ll t[4 * MAXN], lazy[4 * MAXN];

void push(int v)
{
    t[2 * v] += lazy[v];
    t[2 * v + 1] += lazy[v];

    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];

    lazy[v] = 0;
}

void build(int v, int tl, int tr, vector<ll> &arr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, arr);
        build(2 * v + 1, tm + 1, tr, arr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int l, int r, ll add)
{
    if(l > r)
        return;
    if(tl == l && tr == r)
    {
        t[v] += add;
        lazy[v] += add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        push(v);
        update(2 * v, tl, tm, l, min(r, tm), add);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

ll query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return inf;
    if(tl == l && tr == r)
    {
        return t[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        push(v);
        return min(query(2 * v, tl, tm, l, min(r, tm)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    build(1, 0, n - 1, arr);

    int q;
    cin >> q;
    cin.ignore();
    while(q--)
    {
        vector<int> op;
        int x;

        string in;
        getline(cin, in);
        stringstream ss(in);
        while(ss >> x)
            op.pb(x);

        if(sz(op) == 2)
        {
            int l = op[0], r = op[1];
            ll left = inf, right = inf;
            if(l <= r)
                left = query(1, 0, n - 1, l, r);
            else
                left = query(1, 0, n - 1, l, n - 1), right = query(1, 0, n - 1, 0, r);
            cout << min(left, right) << endl;
        }
        else
        {
            int l = op[0], r = op[1];
            ll v = op[2];
            if(l <= r)
                update(1, 0, n - 1, l, r, v);
            else
                update(1, 0, n - 1, l, n - 1, v), update(1, 0, n - 1, 0, r, v);
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