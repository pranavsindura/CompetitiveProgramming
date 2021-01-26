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
    int n, k;
    string s;
    cin >> n >> k >> s;

    string make;
    for(int i = 0; i < k - 1; i++) make += "()";
    make += string((n - 2 * (k - 1)) / 2, '(');
    make += string((n - 2 * (k - 1)) / 2, ')');

    vector<vector<int>> ops;

    for(int i = 0; i < n; i++)
    {
        int idx = find(s.begin() + i, s.end(), make[i]) - s.begin();
        assert(idx < n);
        ops.pb({i, idx});
        int m = (idx - i + 1);
        for(int j = 0; j < m / 2; j++)
            swap(s[i + j], s[i + m - j - 1]);
    }
    assert(sz(ops) <= n);
    assert(s == make);
    cout << sz(ops) << endl;
    for(auto v : ops)
        cout << v[0] + 1 << " " << v[1] + 1 << endl;
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

