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

void print(vector<pair<int, string>> &ops)
{
    cout << "YES\n";
    vector<pair<int, string>> arr;
    for(auto v : ops)
        if(v.ff)
            arr.pb(v);
    cout << sz(arr) << endl;
    for(auto v : arr)
        cout << v.ff << " " << v.ss << endl;
    exit(0);
}

void cp()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, string>> ops;
    // go down
    int can = min(k, n - 1);
    k -= can;
    ops.pb({can, "D"});
    if(k == 0) print(ops);

    // go up
    can = min(k, n - 1);
    k -= can;
    ops.pb({can, "U"});
    if(k == 0) print(ops);

    for(int i = 1; i < m; i++)
    {
        // go right
        k--;
        ops.pb({1, "R"});
        if(k == 0) print(ops);
        // op 1
        if(n == 1) continue;

        can = min(k / 3, n - 1);
        k -= can * 3;
        ops.pb({can, "DLR"});
        if(k == 0) print(ops);
        if(can < n - 1)
        {
            if(k == 1)
            {
                ops.pb({1, "D"});
                print(ops);
            }
            else if(k == 2)
            {
                ops.pb({1, "D"});
                ops.pb({1, "L"});
                print(ops);
            }
        }
        // go up
        can = min(k, n - 1);
        k -= can;
        ops.pb({can, "U"});
        if(k == 0) print(ops);
    }

    // go left
    can = min(k, m - 1);
    k -= can;
    ops.pb({can, "L"});
    if(k == 0) print(ops);

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

