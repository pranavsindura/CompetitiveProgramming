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

struct node
{
    int pos, neg, zero;
    node(): pos(0), neg(0), zero(0) {}
    node(int pos, int neg, int zero): pos(pos), neg(neg), zero(zero) {}
    node(int val)
    {
        pos = neg = zero = 0;
        if(val == 0)
            zero++;
        else if(val > 0)
            pos++;
        else
            neg++;
    }
};

int arr[MAXN];
node t[4 * MAXN];

node combine(node u, node v)
{
    int pos = u.pos + v.pos;
    int neg = u.neg + v.neg;
    int zero = u.zero + v.zero;
    return node(pos, neg, zero);
}

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        t[v] = node(arr[tl]);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if(tl == tr)
    {
        t[v] = node(new_val);
    }
    else
    {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

node query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return node();
    if(tl == l && r == tr)
        return t[v];
    else
    {
        int tm = (tl + tr) / 2;
        node left = query(v * 2, tl, tm, l, min(r, tm));
        node right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(left, right);
    }

}

void cp()
{
    int n, q;
    while(cin >> n >> q)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        build(1, 0, n - 1);

        string ans;
        char t;
        int u, v;
        while(q--)
        {
            cin >> t >> u >> v;
            if(t == 'C')
                update(1, 0, n - 1, u - 1, v);
            else
            {
                node res = query(1, 0, n - 1, u - 1, v - 1);
                if(res.zero)
                    ans += '0';
                else if(res.neg & 1)
                    ans += '-';
                else
                    ans += '+';
            }
        }
        cout << ans << endl;
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