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
// int arr[MAXN], lazy[4 * MAXN];
// pi t[4 * MAXN];

// void build(int v, int tl, int tr)
// {
//     if(tl == tr)
//         t[v] = {arr[tl], tl};
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         build(v << 1, tl, tm);
//         build(v << 1 | 1, tm + 1, tr);
//         t[v] = min(t[v << 1], t[v << 1 | 1]);
//     }
// }

// void push(int v)
// {
//     t[v << 1].ff += lazy[v];
//     t[v << 1 | 1].ff += lazy[v];
//     lazy[v << 1] += lazy[v];
//     lazy[v << 1 | 1] += lazy[v];
//     lazy[v] = 0;
// }

// void update(int v, int tl, int tr, int l, int r)
// {
//     if(l > r)
//         return;
//     if(tl == l && tr == r)
//     {
//         t[v].ff++;
//         lazy[v]++;
//     }
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         push(v);
//         update(v << 1, tl, tm, l, min(r, tm));
//         update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
//         t[v] = min(t[v << 1], t[v << 1 | 1]);
//     }
// }

// pi query(int v, int tl, int tr, int l, int r)
// {
//     if(l > r)
//         return {INT_MAX, -1};
//     if(tl == l && tr == r)
//         return t[v];
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         push(v);
//         pi left = query(v << 1, tl, tm, l, min(r, tm));
//         pi right = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
//         return min(t[v << 1], t[v << 1 | 1]);
//     }
// }

// void cp()
// {
//     int n, m, w;
//     cin >> n >> m >> w;
//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
//     build(1, 0, n - 1);
//     while(m--)
//     {
//         pi sm = query(1, 0, n - 1, 0, n - 1);
//         int l = sm.ss, r = sm.ss + w - 1;
//         if(r >= n)
//         {
//             int extra = r - n + 1;
//             l -= extra, r -= extra;
//         }
//         update(1, 0, n - 1, l, r);
//     }
//     cout << query(1, 0, n - 1, 0, n - 1).ff;
// }

void cp()
{
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    int lo = 1, hi = 1e9 + 1e5 + 5;
    int ans = *min_element(all(arr));


    auto check = [&](int val)
    {
        vector<int> prev(n);
        int curr = 0, total = 0;
        for(int i = 0; i < n; i++)
        {
            if(i - w >= 0)
                curr -= prev[i - w];
            if(arr[i] + curr < val)
            {
                int need = val - arr[i] - curr;
                prev[i] = need;
                curr += need;
                total += need;
            }
            if(total > m)
                return false;
        }
        return total <= m;
    };

    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(check(mid))
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
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