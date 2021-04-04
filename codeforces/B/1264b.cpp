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

void cp()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b && c)
    {
        if(d > c || a > b)
        {
            cout << "NO\n";
            return;
        }
        string L, M, R;
        for(int i = 0; i < a; i++) L += "0 1 ";
        b -= a;
        for(int i = 0; i < d; i++) R += "2 3 ";
        c -= d;
        int m = min(b, c);
        for(int i = 0; i < m; i++) M += "2 1 ";
        b -= m, c -= m;
        if(b > 1 || c > 1)
        {
            cout << "NO\n";
            return;
        }
        if(b) L = "1 " + L;
        if(c) R = R + "2 ";
        cout << "YES\n";
        cout << L + M + R << endl;
    }
    else if(b)
    {
        if(d > 0)
        {
            cout << "NO\n";
            return;
        }
        string M;
        int m = min(a, b);
        for(int i = 0; i < m; i++) M += "0 1 ";
        a -= m, b -= m;
        if(a > 1 || b > 1)
        {
            cout << "NO\n";
            return;
        }
        if(a) M = M + "0 ";
        if(b) M = "1 " + M;
        cout << "YES\n";
        cout << M << endl;
    }
    else if(c)
    {
        if(a > 0)
        {
            cout << "NO\n";
            return;
        }
        string M;
        int m = min(c, d);
        for(int i = 0; i < m; i++) M += "2 3 ";
        c -= m, d -= m;
        if(c > 1 || d > 1)
        {
            cout << "NO\n";
            return;
        }
        if(c) M = M + "2 ";
        if(d) M = "3 " + M;
        cout << "YES\n";
        cout << M << endl;
    }
    else if(a == 1 && d == 0)
        cout << "YES\n0\n";
    else if(d == 1 && a == 0)
        cout << "YES\n3\n";
    else
        cout << "NO\n";
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
