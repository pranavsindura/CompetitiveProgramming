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
const int MAXN = 2e5 + 5;

int t[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = 1;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

int query(int v, int tl, int tr, int kth)
{
    if(tl == tr)
        return tl;
    else
    {
        int tm = (tl + tr) >> 1;
        if(t[v << 1] >= kth)
            return query(v << 1, tl, tm, kth);
        else
            return query(v << 1 | 1, tm + 1, tr, kth - t[v << 1]);
    }
}

void update(int v, int tl, int tr, int pos, int val)
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
        t[v] = t[v << 1] + t[v << 1 | 1];
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n), ans(n);
    for(int &x : arr)
        cin >> x;

    build(1, 0, n - 1);

    for(int i = n - 1; i >= 0; i--)
    {
        int pos = i + 1 - arr[i];
        // find the index of the pos-th 1
        int idx = query(1, 0, n - 1, pos);
        ans[i] = idx + 1;
        update(1, 0, n - 1, idx, 0);
    }
    for(int x : ans)
        cout << x << " ";
    cout << endl;
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