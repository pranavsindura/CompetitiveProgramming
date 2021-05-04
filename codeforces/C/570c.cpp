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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

pi get(string &s)
{
    int n = ln(s), l = 0;
    int cnt = count(all(s), '.');
    int group = 0;
    while(l < n)
    {
        while(l < n && s[l] != '.') l++;
        if(l == n) break;
        int r = l;
        while(r + 1 < n && s[r + 1] == '.') r++;
        group++;
        l = r + 1;
    }
    return {cnt, group};
}

void cp()
{
    int n, q;
    string s;
    cin >> n >> q >> s;

    pi val = get(s);
    while(q--)
    {
        int x;
        char c;
        cin >> x >> c, x--;

        string S, T;
        if(x - 1 >= 0) S += s[x - 1], T += s[x - 1];
        S += s[x];
        T += c;
        if(x + 1 < n) S += s[x + 1], T += s[x + 1];

        pi A = get(S), B = get(T);
        val.ff += B.ff - A.ff;
        val.ss += B.ss - A.ss;

        s[x] = c;

        cout << val.ff - val.ss << endl;
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
