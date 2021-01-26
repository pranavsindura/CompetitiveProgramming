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
    int k1, k2;
    cin >> s >> k1 >> k2;
    int n = ln(s);

    bool ok = true;
    vector<int> pos;
    int dev = 0, changes = 0;

    for(int i = 0; i < n && ok; i++)
    {
        if(s[i] == 'W') dev++;
        else dev--;

        if((i + 1) % k1 == 0 || (i + 1) % k2 == 0)
        {
            while(dev <= 0 && !pos.empty())
            {
                int x = pos.back();
                pos.pop_back();
                changes++;
                s[x] = 'W';
                dev += 2;
            }
            ok &= dev > 0;
            ok &= dev > 0;
        }
        else
        {
            if(s[i] == 'L') pos.pb(i);
            while(dev <= 0 && !pos.empty())
            {
                int x = pos.back();
                pos.pop_back();
                changes++;
                s[x] = 'W';
                dev += 2;
            }
            ok &= dev > 0;
        }
    }

    if(ok)
        cout << changes << endl << s << endl;
    else
        cout << -1 << endl;
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

