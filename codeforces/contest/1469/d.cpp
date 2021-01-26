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
    int n;
    cin >> n;
    int idx = -1, got = -1;
    for(int i = 1; i <= n; i++)
    {
        int a = i, b = n;
        int steps = 0;
        while(a != 1)
        {
            steps++;
            b = (b + a - 1) / a;
            if(a > b) swap(a, b);
        }
        if(b <= 2 && steps <= 8) idx = i, got = b;
    }
    assert(~idx);

    vector<vector<int>> ops;
    if(got == 1)
    {
        for(int i = 3; i < n; i++)
        {
            if(i == idx) continue;
            ops.pb({i, n});
        }
        int a = idx, b = n;
        int u = idx, v = n;
        while(a != 1)
        {
            ops.pb({v, u});
            b = (b + a - 1) / a;
            if(a > b) swap(a, b), swap(u, v);
        }
    }
    else
    {
        for(int i = 2; i < n; i++)
        {
            if(i == idx) continue;
            ops.pb({i, n});
        }
        int a = idx, b = n;
        int u = idx, v = n;
        while(a != 1)
        {
            ops.pb({v, u});
            b = (b + a - 1) / a;
            if(a > b) swap(a, b), swap(u, v);
        }
    }

    assert(sz(ops) <= n + 5);
    
    cout << sz(ops) << endl;
    for(auto v : ops)
        cout << v[0] << " " << v[1] << endl;
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

