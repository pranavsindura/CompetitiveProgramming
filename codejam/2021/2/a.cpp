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
const int MAXN = 1e6 + 5;

void cp()
{
    int t, n;
    cin >> t >> n;
    while(t--)
    {
        int p = 1;
        for(int i = 0; i < n - 1; i++)
        {
            cout << "M " << p << " " << n << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x != p)
            {
                cout << "S " << p << " " << x << endl;
                cout.flush();
                cin >> x;
                assert(x == 1);
            }
            p++;
        }
        cout << "D" << endl;
        cout.flush();
        int x;
        cin >> x;
        assert(x == 1);
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
