#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    string s, t;
    if(a[0] != 'X') s += a[0];
    if(a[1] != 'X') s += a[1];
    if(b[1] != 'X') s += b[1];
    if(b[0] != 'X') s += b[0];
    if(c[0] != 'X') t += c[0];
    if(c[1] != 'X') t += c[1];
    if(d[1] != 'X') t += d[1];
    if(d[0] != 'X') t += d[0];
    bool ok = s == t;
    for(int i = 0; i < 3; i++)
    {
        char x = t.back();
        t.pop_back();
        t = x + t;
        ok |= s == t;
    }
    cout << (ok ? "YES\n" : "NO\n");
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

