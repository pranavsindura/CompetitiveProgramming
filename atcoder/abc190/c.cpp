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
    int n, m, k;
    cin >> n >> m;
    vector<array<int, 2>> dish(m);
    for(auto &v : dish)
        cin >> v[0] >> v[1], v[0]--,v[1]--;
    cin >> k;
    vector<array<int, 2>> place(k);
    for(auto &v : place)
        cin >> v[0] >> v[1], v[0]--, v[1]--;

    int ans = 0;
    for(int mask = 0; mask < 1 << k; mask++)
    {
        vector<int> picked(n);
        for(int i = 0; i < k; i++)
            picked[place[i][(mask >> i) & 1]] = 1;
        int me = 0;
        for(auto v: dish)
        	me += picked[v[0]] & picked[v[1]];
        ans = max(me, ans);
    }

    cout << ans << endl;
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

