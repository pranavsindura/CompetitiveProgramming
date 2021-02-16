#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    ll total = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        if(!pq.empty())
        {
            int S = pq.top();
            pq.pop();
            if(S <= arr[i]) total += arr[i] - S, pq.push(arr[i]);
            else pq.push(S);
        }
        pq.push(arr[i]);
    }

    cout << total << endl;
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

/*
#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e6 + 5;

vector<vector<int>> pos(MAXN);

using ftype = pi;

ftype t[4 * MAXN];
ftype e = {MAXN, -1}; // Identity Element

ftype combine(ftype L, ftype R)
{
    return min(L, R);
}

void build(int v, int tl, int tr, vector<int> &arr)
{
    if(tl == tr)
        t[v] = {arr[tl], tl};
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void setpt(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            setpt(v << 1, tl, tm, pos, val);
        else
            setpt(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

ftype query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return e;

    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        ftype L = query(v << 1, tl, tm, l, min(r, tm));
        ftype R = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(L, R);
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i], pos[arr[i]].push_back(i);

    build(1, 0, n - 1, arr);

    ll total = 0;

    for(int mx = MAXN - 1; mx >= 1; mx--)
    {
        for(int idx_mx : pos[mx])
        {
            pi Q = query(1, 0, n - 1, 0, idx_mx - 1);
            int mn = Q.first, idx_mn = Q.second;
            if(~idx_mn && mn <= mx)
                total += mx - mn, setpt(1, 0, n - 1, idx_mn, e), setpt(1, 0, n - 1, idx_mx, e);
        }
    }

    cout << total << endl;
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

*/