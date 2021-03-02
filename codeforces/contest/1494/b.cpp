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
    vector<int> p(4);
    for(int &x: p)
    	cin >> x;

    bool ok = false;
    for(int mask = 0; mask < 1 << 4; mask++)
    {
        vector<int> q = p;
        if((mask >> 0) & 1) q[0]--, q[3]--;
        if((mask >> 1) & 1) q[2]--, q[3]--;
        if((mask >> 2) & 1) q[2]--, q[1]--;
        if((mask >> 3) & 1) q[0]--, q[1]--;
        ok |= count_if(all(q), [&](int a)
        {
            return a >= 0 && a <= n - 2;
        }) == 4;
    }
    cout << (ok ? "YES\n" : "NO\n");
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
