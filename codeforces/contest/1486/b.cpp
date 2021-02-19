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
    vector<array<int, 2>> p(n);
    for(auto &v : p)
        cin >> v[0] >> v[1];

    ll best = LLONG_MAX;
    for(int i = 0; i < n; i++)
    {
        ll me = 0;
        for(int j = 0; j < n; j++)
            me += abs(p[i][0] - p[j][0]);
        best = min(best, me);
    }

    set<int> X;
    for(int i = 0; i < n; i++)
    {
        ll me = 0;
        for(int j = 0; j < n; j++)
            me += abs(p[i][0] - p[j][0]);
        if(best == me) X.insert(p[i][0]);
    }

    best = LLONG_MAX;
    for(int i = 0; i < n; i++)
    {
        ll me = 0;
        for(int j = 0; j < n; j++)
            me += abs(p[i][1] - p[j][1]);
        best = min(best, me);
    }

    set<int> Y;
    for(int i = 0; i < n; i++)
    {
        ll me = 0;
        for(int j = 0; j < n; j++)
            me += abs(p[i][1] - p[j][1]);
        if(best == me) Y.insert(p[i][1]);
    }
    int x = *X.rbegin() - *X.begin() + 1;
    int y = *Y.rbegin() - *Y.begin() + 1;
    // dbg(x);
    // dbg(y);
    ll total = x * 1LL * y;
    cout << total << endl;
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
