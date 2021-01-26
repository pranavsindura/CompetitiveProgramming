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
int arr[MAXN];

ll t1[4 * MAXN], t2[4 * MAXN];

ll query(int v, int tl, int tr, int l, int r, ll t[])
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

void update(int v, int tl, int tr, int pos, ll val, ll t[])
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val, t);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val, t);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        // inversion count of arr[i]
        ll val = query(1, 0, MAXN, arr[i] + 1, MAXN, t1);
        // update inversion in t2
        update(1, 0, n - 1, i, val, t2);

        // put arr[i] in t1
        update(1, 0, MAXN, arr[i], 1, t1);
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n - 1, l, r, t2) << endl;
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