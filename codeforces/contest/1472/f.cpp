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
    int n, m;
    cin >> n >> m;
    map<int, set<int>> block;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        block[y].insert(x);
    }

    block[0].insert(1), block[0].insert(2);
    block[n + 1].insert(1), block[n + 1].insert(2);

    vector<int> arr;
    for(auto x : block) arr.pb(x.ff);

    bool ok = true, b = false;
    for(int i = 1; i < sz(arr); i++)
    {
        int L = arr[i - 1], R = arr[i];
        if(sz(block[L]) == 2 && sz(block[R]) == 2)
            b = true;
        else if(sz(block[L]) == 2 && sz(block[R]) == 1)
            b = false;
        else if(sz(block[L]) == 1 && sz(block[R]) == 2)
            ok &= b;
        else
        {
            int x = *block[L].begin();
            int y = *block[R].begin();
            if(!b) ok &= ok &= (R - L + (x == y)) % 2 == 0;
            b ^= true;
        }
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

