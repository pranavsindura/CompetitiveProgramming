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

int idx(char x)
{
    if(x == 'W') return 0;
    if(x == 'M') return 1;
    if(x == 'C') return 2;
    return 3;
}

vector<bitset<4>> hero, need;
bool can[5];
void solve(int i, int n, int mask, int taken)
{
    if(i == n)
    {
        int x = 15 - taken;
        need[__builtin_popcount(taken)] |= bitset<4>(x);
        can[__builtin_popcount(taken)] = 1;
    }
    else
    {
        int nmask = mask & (mask - 1);
        int b = __builtin_ffs(mask ^ nmask) - 1;
        for(int j = 0; j < 4; j++)
            if(hero[b][j])
                solve(i + 1, n, nmask, taken | (1 << j));
    }
}

void cp()
{
    int n;
    cin >> n;
    hero.resize(n);
    need.resize(5);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(char x : s)
            hero[i][idx(x)] = 1;
    }

    for(int mask = 0; mask < 1 << n; mask++)
    {
        if(__builtin_popcount(mask) > 4) continue;
        solve(0, __builtin_popcount(mask), mask, 0);
    }

    for(int i = 4; i >= 1; i--)
    {
        if(can[i])
        {
            cout << i << endl;
            if(need[i].count())
            {
                string s = "Looking for ";
                if(need[i][0]) s += "warrior ";
                if(need[i][1]) s += "mage ";
                if(need[i][2]) s += "cleric ";
                if(need[i][3]) s += "rogue ";
                s.pop_back();
                cout << s << endl;
            }
            return;
        }
    }

    assert(false);
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

