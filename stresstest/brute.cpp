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
const int MAXN = 3e6 + 5;

using ftype = int;

array<ftype, 4 * MAXN> t;
ftype e = 0; // Identity Element

ftype combine(ftype L, ftype R)
{
    return L + R;
}

void updatept(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] += val, t[v] = max(t[v], 0);
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            updatept(v << 1, tl, tm, pos, val);
        else
            updatept(v << 1 | 1, tm + 1, tr, pos, val);
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


int kth_one(int v, int tl, int tr, int k) // Index of kth one
{
    if(k > t[v])
        return -1; // Does not exist
    if(tl == tr)
        return tl;
    else
    {
        int tm = (tl + tr) >> 1;
        if(t[v << 1] >= k)
            return kth_one(v << 1, tl, tm, k);
        else
            return kth_one(v << 1 | 1, tm + 1, tr, k - t[v << 1]);
    }
}

int actual[MAXN];
int qT[MAXN], qX[MAXN];

void cp()
{
    int q = 0;
    int T, X;
    while(cin >> T && ~T)
        cin >> X, qT[q] = T, qX[q] = X, q++;

    map<int, int> comp;
    comp[0];
    for(int i = 0; i < q; i++) if(qT[i] < 4) comp[qX[i]];

    int N = 0;
    for(auto &x : comp)
        x.second = N++;

    for(auto x : comp)
        actual[x.second] = x.first;

    for(int i = 0; i < q; i++)
    {
        T = qT[i], X = qX[i];
        if(T == 1) updatept(1, 0, N - 1, comp[X], 1);
        else if(T == 2) updatept(1, 0, N - 1, comp[X], -1);
        else if(T == 3)
        {
            int cnt = query(1, 0, N - 1, comp[X], comp[X]);
            if(cnt == 0) cout << -1 << endl;
            else cout << query(1, 0, N - 1, 0, comp[X] - 1) + 1 << endl;
        }
        else
        {
            if(X == 0) cout << -1 << endl;
            else
            {
                int p = kth_one(1, 0, N - 1, X);
                if(~p) cout << actual[p] << endl;
                else cout << -1 << endl;
            }
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
