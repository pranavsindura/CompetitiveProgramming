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
const int MAXN = 1e6 + 5;

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

array<int, MAXN> lcm, v, arr;

void cp()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        while(x > 1)
        {
            int cnt = 0;
            int f = lp[x];
            while(x > 1 && lp[x] == f)
                cnt++, x /= f;
            lcm[f] = max(lcm[f], cnt);
        }
    }

    while(k > 1) v[lp[k]]++, k /= lp[k];

    bool ok = true;
    for(int i = 2; i < MAXN && ok; i++)
        ok &= v[i] <= lcm[i];

    cout << (ok ? "Yes\n" : "No\n");
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
