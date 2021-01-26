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

// SAVING SUBARRAYS IN RANGE
// 0.69s, 103MB
// multiset<int, greater<int>> t[4 * MAXN];

// void build(int v, int tl, int tr)
// {

//     if(tl == tr)
//         t[v].insert(arr[tl]);
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         build(v << 1, tl, tm);
//         build(v << 1 | 1, tm + 1, tr);
//         merge(all(t[v << 1]), all(t[v << 1 | 1]), inserter(t[v], t[v].begin()));
//     }
// }

// pi query(int v, int tl, int tr, int l, int r)
// {
//     if(l > r)
//         return {-1, -1};
//     if(tl == l && tr == r)
//     {
//         pi res = {-1, -1};

//         int f = *t[v].begin();
//         t[v].erase(t[v].begin());

//         res.ff = f;

//         if(!t[v].empty())
//         {
//             int s = *t[v].begin();
//             res.ss = s;
//         }

//         t[v].insert(f);

//         return res;
//     }
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         pi left = query(v << 1, tl, tm, l, min(r, tm));
//         pi right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
//         vector<int> temp = {left.ff, left.ss, right.ff, right.ss};
//         sort(allr(temp));
//         return {temp[0], temp[1]};
//     }
// }

// void update(int v, int tl, int tr, int pos, int val)
// {
//     if(tl == tr)
//     {
//         t[v].clear();
//         t[v].insert(val);
//     }
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         if(pos <= tm)
//             update(v << 1, tl, tm, pos, val);
//         else
//             update(v << 1 | 1, tm + 1, tr, pos, val);
//         t[v].erase(t[v].find(arr[pos]));
//         t[v].insert(val);
//     }
// }

// void cp()
// {
//     int n, q;
//     cin >> n;
//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
//     build(1, 0, n - 1);
//     cin >> q;
//     while(q--)
//     {
//         char t;
//         int u, v;
//         cin >> t >> u >> v;
//         if(t == 'Q')
//         {
//             pi res = query(1, 0, n - 1, u - 1, v - 1);
//             cout << res.ff + res.ss << endl;
//         }
//         else
//             update(1, 0, n - 1, u - 1, v), arr[u - 1] = v;
//     }
// }


// Query for Max twice
// 0.06s, 5.8MB
pi t[4 * MAXN];
void build(int v, int tl, int tr)
{

    if(tl == tr)
        t[v] = {arr[tl], tl};
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

pi query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return {-1, 0};
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        pi left = query(v << 1, tl, tm, l, min(r, tm));
        pi right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return max(left, right);
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
    {
        t[v] = {val, tl};
    }
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


void cp()
{
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    cin >> q;
    while(q--)
    {
        char t;
        int u, v;
        cin >> t >> u >> v;
        if(t == 'Q')
        {
            pi mx = query(1, 0, n - 1, u - 1, v - 1);
            update(1, 0, n - 1, mx.ss, -1);
            pi mx2 = query(1, 0, n - 1, u - 1, v - 1);
            update(1, 0, n - 1, mx.ss, mx.ff);
            cout << mx.ff + mx2.ff << endl;
        }
        else
            update(1, 0, n - 1, u - 1, v);
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