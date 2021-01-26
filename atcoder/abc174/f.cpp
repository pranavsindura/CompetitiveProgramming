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
const int MAXN = 5e5 + 5;


// struct query
// {
//     int l, r, idx;
// };

// int arr[MAXN], t[4 * MAXN], last[MAXN], ans[MAXN];
// vector<query> queries;

// void update(int v, int tl, int tr, int pos, int val)
// {
//     if(tl == tr)
//         t[v] += val;
//     else
//     {
//         int tm = (tl + tr) / 2;
//         if(pos <= tm)
//             update(2 * v, tl, tm, pos, val);
//         else
//             update(2 * v + 1, tm + 1, tr, pos, val);
//         t[v] = t[2 * v] + t[2 * v + 1];
//     }
// }

// int sum(int v, int tl, int tr, int l, int r)
// {
//     if(l > r)
//         return 0;
//     if(tl == l && tr == r)
//     {
//         return t[v];
//     }
//     else
//     {
//         int tm = (tl + tr) / 2;
//         return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
//     }
// }

// void cp()
// {
//     int n, q;
//     cin >> n >> q;
//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
//     for(int i = 0; i < q; i++)
//     {
//         int l, r;
//         cin >> l >> r;
//         l--, r--;
//         queries.pb({l, r, i});
//     }
//     sort(all(queries), [&](query a, query b)
//     {
//         return a.r < b.r;
//     });

//     clr(last, -1);

//     int pos = 0;
//     for(int i = 0; i < n; i++)
//     {
//         // reduce 1 at pos last[arr[i]]
//         if(last[arr[i]] != -1)
//             update(1, 0, n - 1, last[arr[i]], -1);

//         last[arr[i]] = i;
//         update(1, 0, n - 1, last[arr[i]], 1);

//         while(pos < q && queries[pos].r == i)
//             ans[queries[pos].idx] = sum(1, 0, n - 1, queries[pos].l, queries[pos].r), pos++;
//     }

//     for (int i = 0; i < q; i++)
//         cout << ans[i] << endl;
// }

int arr[MAXN];
vector<int> t[4 * MAXN];

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v].pb(arr[tl]);
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        int n = sz(t[v << 1]);
        int m = sz(t[v << 1 | 1]);
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(t[v << 1][i] < t[v << 1 | 1][j])
            {
                t[v].pb(t[v << 1][i]);
                i++;
            }
            else if(t[v << 1][i] > t[v << 1 | 1][j])
            {
                t[v].pb(t[v << 1 | 1][j]);
                j++;
            }
            else
            {
                t[v].pb(t[v << 1 | 1][j]);
                i++, j++;
            }
        }

        while(i < n)
        {
            t[v].pb(t[v << 1][i]);
            i++;
        }

        while(j < m)
        {
            t[v].pb(t[v << 1 | 1][j]);
            j++;
        }
    }
}

vector<int> query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return vector<int>();
    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        vector<int> left = query(v << 1, tl, tm, l, min(r, tm));
        vector<int> right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        int n = sz(left);
        int m = sz(right);
        vector<int> me;
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(left[i] < right[j])
            {
                me.pb(left[i]);
                i++;
            }
            else if(left[i] > right[j])
            {
                me.pb(right[j]);
                j++;
            }
            else
            {
                me.pb(right[j]);
                i++, j++;
            }
        }

        while(i < n)
        {
            me.pb(left[i]);
            i++;
        }

        while(j < m)
        {
            me.pb(right[j]);
            j++;
        }
        return me;
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        vector<int> me = query(1, 0, n - 1, l, r);
        cout << sz(me) << endl;
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