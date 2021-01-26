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
using pi = pair<ll, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 6e5 + 5;

ll p31[MAXN], p53[MAXN];
void init()
{
    p31[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p31[i] = (p31[i - 1] * 31) % mod;
    p53[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p53[i] = (p53[i - 1] * 53) % mod;
}

pi calc(string &s)
{
    ll h31 = 0, h53 = 0;
    for(int i = 0; i < ln(s); i++)
    {
        h31 += ((s[i] - 'a' + 1) * p31[i]) % mod;
        h31 %= mod;
        h53 += ((s[i] - 'a' + 1) * p53[i]) % mod;
        h53 %= mod;
    }
    return {h31, h53};
}

void cp()
{
    init();
    int n, q;
    cin >> n >> q;

    set<pi> st;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.insert(calc(s));
    }

    while(q--)
    {
        string s;
        cin >> s;
        pi H = calc(s);
        bool ok = false;
        for(int i = 0; i < ln(s); i++)
        {
            for(char c = 'a'; c <= 'c'; c++)
            {
                if(c == s[i]) continue;
                ll h31 = H.ff, h53 = H.ss;
                // remove
                h31 -= ((s[i] - 'a' + 1) * p31[i]) % mod;
                h31 = (h31 + mod) % mod;
                h53 -= ((s[i] - 'a' + 1) * p53[i]) % mod;
                h53 = (h53 + mod) % mod;
                // add
                h31 += ((c - 'a' + 1) * p31[i]) % mod;
                h31 %= mod;
                h53 += ((c - 'a' + 1) * p53[i]) % mod;
                h53 %= mod;

                if(st.count({h31, h53})) ok = true;
            }
        }
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