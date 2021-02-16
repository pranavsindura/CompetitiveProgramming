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
const int inf = 1e9;
const int MAXN = 1e5 + 5;

int h;

int get_max(vector<int> &X, vector<int> &Y)
{
    int mx = -inf;
    if(sz(X) >= 2) mx = max(mx, X[0] + X[1]);
    if(sz(Y) >= 2) mx = max(mx, Y[sz(Y) - 1] + Y[sz(Y) - 2]);
    if(sz(X) >= 1 && sz(Y) >= 1) mx = max(mx, X[0] + Y[sz(Y) - 1] + h);
    return mx;
}

int get_min(vector<int> &X, vector<int> &Y)
{
    int mn = inf;
    if(sz(X) >= 2) mn = min(mn, X[sz(X) - 1] + X[sz(X) - 2]);
    if(sz(Y) >= 2) mn = min(mn, Y[0] + Y[1]);
    if(sz(X) >= 1 && sz(Y) >= 1) mn = min(mn, X[sz(X) - 1] + Y[0] + h);
    return mn;
};

void cp()
{
    int n;
    cin >> n >> h;
    vector<int> arr(n);
    vector<pi> A;
    for(int &x : arr)
        cin >> x;

    for(int i = 0; i < n; i++) A.push_back({arr[i], i});
    sort(all(A));

    int ans = 1e9;
    vector<int> res(n);

    int bestmask = -1, bestpos = -1;

    for(int mask = 0; mask < 8; mask++)
    {
        int a = (mask >> 0) & 1;
        int b = (mask >> 1) & 1;
        int c = (mask >> 2) & 1;
        int d = c;
        int best = 1e9, pos = 1;

        vector<int> Sx, Ey, X, Y;

        if(a == 0) Sx.pb(A[0].first);
        else Y.pb(A[0].first);
        if(b == 0) Sx.pb(A[1].first);
        else Y.pb(A[1].first);

        for(int i = 2; i < n - 2; i++)
            X.push_back(A[i].first);

        if(c == 0) X.pb(A[n - 2].first);
        else Ey.pb(A[n - 2].first);
        if(d == 0) X.pb(A[n - 1].first);
        else Ey.pb(A[n - 1].first);

        reverse(all(X));
        reverse(all(Sx));

        for(int i = 0; i < sz(Sx); i++) X.push_back(Sx[i]);
        for(int i = 0; i < sz(Ey); i++) Y.push_back(Ey[i]);

        int mx = get_max(X, Y);
        int mn = get_min(X, Y);

        for(int i = 0; i < sz(Sx); i++) X.pop_back();
        for(int i = 0; i < sz(Ey); i++) Y.pop_back();

        best = mx - mn;
        // for(int i = 2; i < n - 2; i++)
        // {
        //     X.pop_back();
        //     Y.push_back(A[i].first);
        //     for(int i = 0; i < sz(Sx); i++) X.push_back(Sx[i]);
        //     for(int i = 0; i < sz(Ey); i++) Y.push_back(Ey[i]);

        //     mx = get_max(X, Y);
        //     mn = get_min(X, Y);

        //     for(int i = 0; i < sz(Sx); i++) X.pop_back();
        //     for(int i = 0; i < sz(Ey); i++) Y.pop_back();
        //     if(mx - mn < best)
        //         best = mx - mn, pos = i;
        // }

        if(best < ans)
        {
            ans = best;
            for(int i = 2; i <= pos; i++) res[A[i].second] = 1;
            for(int i = pos + 1; i < n - 2; i++) res[A[i].second] = 0;
            res[A[0].second] = a, res[A[1].second] = b;
            res[A[n - 2].second] = c, res[A[n - 1].second] = d;
            bestmask = mask, bestpos = pos;
        }
    }

    if(n == 2) ans = 0, res = {1, 1};
    else if(n == 3)
    {
        ans = 1e9;
        int bestmask = -1;
        for(int mask = 0; mask < 1 << 3; mask++)
        {
            vector<int> X, Y;
            for(int i = 0; i < 3; i++)
                if((mask >> i) & 1) Y.pb(arr[i]);
                else X.pb(arr[i]);
            sort(all(Y));
            sort(allr(X));
            int mx = get_max(X, Y);
            int mn = get_min(X, Y);
            if(mx - mn <= ans)
                ans = mx - mn, bestmask = mask;
        }
        for(int i = 0; i < 3; i++)
            res[i] = (bestmask >> i) & 1;
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++)
        cout << res[i] + 1 << " ";
    cout << endl;
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
