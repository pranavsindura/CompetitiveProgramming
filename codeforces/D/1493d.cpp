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
const int MAXN = 2e5 + 5;

int lp[MAXN];
vector<int> prime;
void sieve()
{
    lp[0] = lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i]) lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

void cp()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    
    vector<map<int, int>> pf(n);
    vector<set<pi>> freq(MAXN);

    ll g = 1;

    auto mul = [&](int i, int k)
    {
        int sm = sz(freq[k]) < n ? 0 : freq[k].begin()->first;
        freq[k].erase({pf[i][k], i});
        pf[i][k]++;
        freq[k].insert({pf[i][k], i});
        int now = sz(freq[k]) < n ? 0 : freq[k].begin()->first;
        if(sm < now) g = (g * k) % mod;
    };

    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        while(x > 1)
            mul(i, lp[x]), x /= lp[x];
    }

    while(q--)
    {
        int i, x;
        cin >> i >> x;
        i--;
        while(x > 1)
            mul(i, lp[x]), x /= lp[x];

        cout << g << endl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    sieve();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
