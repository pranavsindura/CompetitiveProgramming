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

const int M = 12;

void cp()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n), freq(1 << n);

    for(int i = 0; i < n; i++)
        cin >> w[i];

    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        bitset<M> b(s);
        freq[b.to_ulong()]++;
    }

    vector<int> wu(1 << n);
    for(int i = 0; i < 1 << n; i++)
        for(int j = 0; j < n; j++)
            if((i >> j) & 1)
                wu[i] += w[n - j - 1];

    vector<vector<int>> ans(1 << n, vector<int>(101));
    for(unsigned int t = 0; t < 1 << n; t++)
        for(unsigned int s = 0; s < 1 << n; s++)
        {
            int common = (~(s ^ t)) & ((1 << n) - 1);
            int x = wu[common];
            if(x <= 100) ans[t][x] += freq[s];
        }

    for(unsigned int t = 0; t < 1 << n; t++)
        for(int j = 1; j <= 100; j++)
            ans[t][j] += ans[t][j - 1];

    while(q--)
    {
        string s;
        int x;
        cin >> s >> x;
        bitset<M> b(s);
        int u = b.to_ulong();
        cout << ans[u][x] << endl;
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

