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

bool is_prime[MAXN];
vector<int> prime;
void sieve()
{
    clr(is_prime, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i]) prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}

void cp()
{
    int n;
    int TC = 0;
    while(cin >> n && n)
    {
        int p = upper_bound(all(prime), n) - begin(prime);
        p--;
        ll ans = 0;
        for(int i = p; i >= 0; i--)
        {
            int rem = n - prime[i];
            int q = upper_bound(all(prime), rem) - begin(prime);
            q--;
            q = min(q, i - 1);
            ans += q + 1;
        }
        cout << "Case " << ++TC << ": " << ans << endl;
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
