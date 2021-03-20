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
    vector<vector<int>> hex(7, vector<int>(6));
    while(cin >> hex[0][0])
    {
        for(int i = 0; i < 7; i++)
            for(int j = !i; j < 6; j++)
                cin >> hex[i][j];
        bool ok = false;
        vector<int> order(7);
        iota(all(order), 0);
        do
        {
            bool can = true;
            for(int i = 1; i < 7; i++)
            {
                // match number i on 0th piece with ith piece
                int p = find(all(hex[order[i]]), hex[order[0]][i - 1]) - begin(hex[order[i]]);
                int q = find(all(hex[order[i == 6 ? 1 : i + 1]]), hex[order[0]][i % 6]) - begin(hex[order[i == 6 ? 1 : i + 1]]);
                p = (p - 1 + 6) % 6;
                q = (q + 1) % 6;
                can &= hex[order[i]][p] == hex[order[i == 6 ? 1 : i + 1]][q];
            }
            ok |= can;
        }
        while(next_permutation(all(order)));
        cout << (ok ? "YES\n" : "NO\n");
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
