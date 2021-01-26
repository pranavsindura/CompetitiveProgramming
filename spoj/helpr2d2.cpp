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

int t[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = 0;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] -= val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            update(v << 1, tl, tm, pos, val);
        else
            update(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
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
        int tm = (tl + tr) >> 1;
        int left = query(v << 1, tl, tm, l, min(r, tm));
        int right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return max(left, right);
    }
}

void cp()
{
    int k, q;
    cin >> k >> q;
    int N = 0;
    build(1, 0, MAXN - 1);
    int excess = 0;
    cin.ignore();
    while(q > 0)
    {
        string op;
        getline(cin, op);
        stringstream ss(op);
        vector<int> arr;
        if(op[0] == 'b')
        {
            char t;
            int a, b;
            ss >> t >> a >> b;
            arr = vector<int>(a, b);
        }
        else
        {
            int x;
            ss >> x;
            arr.pb(x);
        }
        q -= sz(arr);
        for(int x : arr)
        {
            int lo = 0, hi = N - 1;
            int pos = -1;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if(query(1, 0, MAXN - 1, 0, mid) >= x)
                    pos = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            if(pos == -1) // need new ship
                update(1, 0, MAXN - 1, N, -k), pos = N++, excess += k;
            update(1, 0, MAXN - 1, pos, x);
            excess -= x;
        }
    }
    cout << N << " " << excess << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}