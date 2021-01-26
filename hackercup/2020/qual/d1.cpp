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
const int MAXN = 1e6 + 5;

ll t[4 * MAXN];
bool marked[4 * MAXN];
void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = LLONG_MAX, marked[v] = false;
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
        marked[v] = false;
    }
}

void push(int v)
{
    if(marked[v])
    {
        t[2 * v] = min(t[2 * v], t[v]);
        t[2 * v + 1] = min(t[2 * v + 1], t[v]);
        marked[v] = false;
        marked[2 * v] = marked[2 * v + 1] = true;
    }
}

void update(int v, int tl, int tr, int l, int r, ll new_val)
{
    if(l > r)
        return;
    if(l == tl && r == tr)
        t[v] = min(t[v], new_val), marked[v] = true;
    else
    {
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), new_val);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
    }
}

ll get(int v, int tl, int tr, int pos)
{
    if(tl == tr)
        return t[v];
    else
    {
        push(v);
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            return get(2 * v, tl, tm, pos);
        else
            return get(2 * v + 1, tm + 1, tr, pos);
    }
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    build(1, 0, n - 1);
    update(1, 0, n - 1, 0, 0, 0);
    arr[0] = 0;
    for(int i = 0; i < n; i++)
    {
        ll my = get(1, 0, n - 1, i);
        if(my == LLONG_MAX || (!arr[i] && i))
            continue;
        ll mn = my + arr[i];
        update(1, 0, n - 1, i, min(i + m, n - 1), mn);
    }
    ll end = get(1, 0, n - 1, n - 1);
    cout << (end == LLONG_MAX ? -1 : end) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}