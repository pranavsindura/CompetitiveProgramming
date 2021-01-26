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
const int MAXN = 1e5 + 5;

void cp()
{
    int n, q;
    cin >> n >> q;
    string op;
    cin >> op;
    op = " " + op;
    vector<vector<int>> pref(n + 2, vector<int>(2));
    vector<vector<int>> suff(n + 2, vector<int>(2));
    vector<int> at(n + 2);
    int mn = 0, mx = 0, x = 0;
    for(int i = 1; i <= n; i++)
    {
        if(op[i] == '+') x++;
        else x--;
        at[i] = x;
        mn = min(mn, x);
        mx = max(mx, x);
        pref[i] = {mn, mx};
    }
    int plus = 0, minus = 0;
    mn = 0, mx = 0, x = 0;
    for(int i = n; i >= 1; i--)
    {
        if(op[i] == '+') mx++, mn++;
        else mx--, mn--;
        mx = max(mx, 0);
        mn = min(mn, 0);
        suff[i] = {mn, mx};
    }

    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int a = pref[l - 1][0], b = pref[l - 1][1];
        int c = at[l - 1] + suff[r + 1][0], d = at[l - 1] + suff[r + 1][1];
        int L = min(a, c), R = max(b, d);
        cout << R - L + 1 << endl;
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
    }
    return 0;
}

