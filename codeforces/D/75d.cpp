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
const int MAXN = 3e5 + 5;

struct node
{
    ll pref, suff, sum, ans;
    node(): pref(INT_MIN), suff(INT_MIN), sum(INT_MIN), ans(INT_MIN) {}
    node(ll pref, ll suff, ll sum, ll ans): pref(pref), suff(suff), sum(sum), ans(ans) {}
};

node combine(node left, node right)
{
    node res;
    res.ans = max({left.ans, right.ans, left.suff + right.pref});
    res.pref = max(left.pref, left.sum + right.pref);
    res.suff = max(right.suff, left.suff + right.sum);
    res.sum = left.sum + right.sum;
    return res;
}

node t[4 * MAXN];

vector<node> segs;

void update(int v, int tl, int tr, int pos, node val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<ll> arr(k);
        for(ll &x : arr)
            cin >> x;
        ll pref = LLONG_MIN, suff = LLONG_MIN, sum = 0, ans = LLONG_MIN;
        ll acc = 0;
        for(ll x : arr)
            acc += x, pref = max(pref, acc);
        sum = acc;
        acc = 0;
        for(auto it = arr.rbegin(); it != arr.rend(); it++)
            acc += *it, suff = max(suff, acc);
        acc = 0;
        for(ll x : arr)
        {
            ll curr = max(acc + x, x);
            ans = max(ans, curr);
            acc = curr;
        }
        segs.pb(node(pref, suff, sum, ans));
    }

    for(int i = 0; i < m; i++)
    {
        int pos;
        cin >> pos;
        pos--;
        update(1, 0, m - 1, i, segs[pos]);
    }

    cout << t[1].ans << endl;
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