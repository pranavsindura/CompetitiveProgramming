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
const int MAXN = 3e4 + 5;

array<int, MAXN> arr, queries;

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < m; i++)
        cin >> queries[i];

    multiset<pi> st;
    multiset<pi>::iterator it;

    int K = 0, T = 0;
    for(int i = 0; i < m; i++)
    {
        while(K < queries[i])
        {
            if(st.empty()) st.insert({arr[K], T++}), it = st.begin();
            else
            {
                if(it == st.end())
                {
                    int x = st.rbegin()->ff;
                    auto it2 = st.insert({arr[K], T++});
                    if(arr[K] < x)
                    	it--;
                    else
                    	it = it2;
                }
                else
                {
                    int x = it->ff;
                    st.insert({arr[K], T++});
                    if(arr[K] < x)
                        it--;
                }
            }
            K++;
        }
        cout << it->ff << endl;
        it++;
    }
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
        if(t) cout << endl;
    }
    return 0;
}

// array<int, MAXN> arr, queries;
// array<int, 4 * MAXN> t;

// void build(int v, int tl, int tr)
// {
//     if(tl == tr)
//         t[v] = 0;
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         build(v << 1, tl, tm);
//         build(v << 1 | 1, tm + 1, tr);
//         t[v] = t[v << 1] + t[v << 1 | 1];
//     }
// }

// int query(int v, int tl, int tr, int l, int r)
// {
//     if(l > r) return 0;
//     if(tl == l && tr == r)
//         return t[v];
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         return query(v << 1, tl, tm, l, min(r, tm)) + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
//     }
// }

// void update(int v, int tl, int tr, int pos, int val)
// {
//     if(tl == tr)
//         t[v] += val;
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         if(pos <= tm)
//             update(v << 1, tl, tm, pos, val);
//         else
//             update(v << 1 | 1, tm + 1, tr, pos, val);
//         t[v] = t[v << 1] + t[v << 1 | 1];
//     }
// }

// void cp()
// {
//     int n, m;
//     cin >> n >> m;
//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
//     for(int i = 0; i < m; i++)
//         cin >> queries[i];

//     map<int, int> comp, revcomp;
//     for(int i = 0; i < n; i++)
//         comp[arr[i]];
//     int N = 0;
//     for(auto &x : comp)
//         x.ss = N++;
//     for(auto x : comp)
//         revcomp[x.ss] = x.ff;

//     build(1, 0, N - 1);

//     int K = 0;
//     for(int i = 0; i < m; i++)
//     {
//         while(K < queries[i])
//             update(1, 0, N - 1, comp[arr[K]], 1), K++;
//         int idx = -1;
//         int lo = 0, hi = N - 1;
//         while(lo <= hi)
//         {
//             int mid = (lo + hi) >> 1;
//             int q = query(1, 0, N - 1, 0, mid);
//             if(q >= (i + 1))
//                 idx = mid, hi = mid - 1;
//             else
//                 lo = mid + 1;
//         }
//         assert(~idx);
//         cout << revcomp[idx] << endl;
//     }
// }

// int main()
// {
//     FASTIO;
//     int t;
//     t = 1;
//     cin >> t;
//     while(t--)
//     {
//         cp();
//         if(t) cout << endl;
//     }
//     return 0;
// }

