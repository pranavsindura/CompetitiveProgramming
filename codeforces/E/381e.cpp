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
string s;
pi t[4 * MAXN];

pi combine(pi left, pi right)
{
    int match = min(left.ff, right.ss);
    return {left.ff + right.ff - match, left.ss + right.ss - match};
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v] = {s[tl] == '(', s[tl] == ')'};
    }
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

pi query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return {0, 0};
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        pi left = query(v << 1, tl, tm, l, min(r, tm));
        pi right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(left, right);
    }
}

void cp()
{
    int n, q;
    cin >> s >> q;
    n = ln(s);
    build(1, 0, n - 1);
    int l, r;
    while(q--)
    {
        cin >> l >> r;
        l--, r--;
        int len = r - l + 1;
        pi excess = query(1, 0, n - 1, l, r);
        len -= (excess.ff + excess.ss);
        cout << len << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
        cp();
    return 0;
}