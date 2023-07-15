#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

long long setBitCount(int N, string S, int X) 
{
    long long ans = 0;

    vector<int> pref;
    for(char x: S) pref.push_back(x - '0');
    partial_sum(pref.begin(), pref.end(), pref.begin());

    for(int i = 0; i < N; i++)
    {
        int lo = i, hi = N - 1, p = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            int sum = pref[mid] - (i ? pref[i - 1] : 0);
            if(sum >= X)
                p = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        if(p == -1) continue;
        ans += N - p;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int N, X;
        string S;
        cin >> N >> S >> X;
        cout << setBitCount(N, S, X) << endl;
    }
}
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1e6 + 5;

// struct node {
//     int first, last, pref, suff, len, ans;
//     node(): first(0), last(0), pref(0), suff(0), len(0), ans(0){};
//     node(int _first, int _last, int _pref, int _suff, int _ans, int _len): first(_first), last(_last), ans(_ans), pref(_pref), suff(_suff), len(_len) {}
// };

// using ftype = node;

// ftype t[4 * MAXN];
// ftype e = node(0, INT_MAX, 0, 0, 0, 0); // Identity Element

// ftype combine(ftype L, ftype R)
// {
//     int first = L.first;
//     int last = R.last;
//     int ans = max(L.ans, R.ans);
//     if(L.last <= R.first)
//         ans = max(ans, L.suff + R.pref);
//     int len = L.len + R.len;
//     int pref = L.pref, suff = R.suff;
//     if(L.len == L.pref && L.last <= R.first) pref = L.len + R.pref;
//     if(R.len == R.suff && L.last <= R.first) suff = L.suff + R.len;

//     return node(first, last, pref, suff, ans, len);
// }

// void build(int v, int tl, int tr, vector<int> &arr)
// {
//     if(tl == tr)
//         t[v] = node(arr[tl], arr[tl], 1, 1, 1, 1);
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         build(v << 1, tl, tm, arr);
//         build(v << 1 | 1, tm + 1, tr, arr);
//         t[v] = combine(t[v << 1], t[v << 1 | 1]);
//     }
// }

// ftype query(int v, int tl, int tr, int l, int r)
// {
//     if(l > r) return e;

//     if(tl == l && tr == r)
//         return t[v];
//     else
//     {
//         int tm = (tl + tr) >> 1;
//         ftype L = query(v << 1, tl, tm, l, min(r, tm));
//         ftype R = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
//         return combine(L, R);
//     }
// }

// vector<int> solve(int n, vector<int> &A, int q, vector<vector<int>> &queries) 
// {
//     build(1, 0, n - 1, A);
//     vector<int> ans;
//     for(int i = 0; i < q; i++)
//     {
//         int l = queries[i][0] - 1, r = queries[i][1] - 1;
//         ans.push_back(query(1, 0, n - 1, l, r).ans);
//     }

//     return ans;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n, q;
//         cin >> n;
//         vector<int> A(n);
//         for(int &x: A)
//             cin >> x;
//         cin >> q;
//         vector<vector<int>> queries;
//         for(int i = 0; i < q; i++)
//         {
//             int l, r;
//             cin >> l >> r;
//             queries.push_back({l, r});
//         }

//         vector<int> ans = solve(n, A, q, queries);
//         for(int x: ans)
//             cout << x << endl;
//     }
// }