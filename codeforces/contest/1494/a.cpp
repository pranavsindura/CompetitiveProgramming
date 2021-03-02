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
    string s;
    cin >> s;
    bool ok = false;
    for(int mask = 0; mask < 1 << 3; mask++)
    {
        string place;
        place += ((mask >> 0) & 1) ? '(' : ')';
        place += ((mask >> 1) & 1) ? '(' : ')';
        place += ((mask >> 2) & 1) ? '(' : ')';

        string t;
        for(char x : s) t += place[x - 'A'];

        bool can = true;
        int db = 0;
        for(char x : t)
            if(x == '(') db++;
            else db--, can &= db >= 0;
        can &= db == 0;
        ok |= can;
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
