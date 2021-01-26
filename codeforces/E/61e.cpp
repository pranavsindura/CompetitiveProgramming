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
map<int, int> comp;

int t_left[4 * MAXN], t_right[4 * MAXN];
void update(int v, int tl, int tr, int pos, int val, int t[])
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val, t);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val, t);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

int query(int v, int tl, int tr, int l, int r, int t[])
{
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, min(r, tm), t) + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, t);
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x, comp[x];

    int num = 1;
    for(auto &x : comp)
        x.ss = num++;

    for(int &x : arr)
        x = comp[x];

    for(int x : arr)
        update(1, 0, num, x, 1, t_right);

    ll ans = 0;
    for(int x : arr)
    {
        update(1, 0, num, x, 0, t_right);
        ll left = query(1, 0, num, x + 1, num, t_left);
        ll right = query(1, 0, num, 0, x - 1, t_right);
        ans += left * right;
        update(1, 0, num, x, 1, t_left);
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