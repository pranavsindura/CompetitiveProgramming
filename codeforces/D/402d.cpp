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
const int MAXN = 4e4 + 5;

bool is_prime[MAXN];
vector<int> prime;

void init()
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

vector<int> arr, bad;

pi get(int n)
{
    int G = 0, B = 0;
    for(int i = 0; i < sz(prime) && n >= prime[i]; i++)
    {
        bool is_bad = binary_search(all(bad), prime[i]);
        while(n % prime[i] == 0)
            n /= prime[i], G += !is_bad, B += is_bad;
    }
    // if n > 1, it should be a prime number
    if(binary_search(all(bad), n)) B++;
    else if(n > 1) G++;
    return {G, B};
}

void cp()
{
    int n, m;
    cin >> n >> m;
    arr.resize(n), bad.resize(m);
    for(int &x : arr)
        cin >> x;
    for(int &x : bad)
        cin >> x;

    int total = 0;
    for(int i = 0; i < n; i++)
    {
        pi val = get(arr[i]);
        total += val.ff - val.ss;
    }

    int ans = total;

    vector<int> have(n);

    int g = 0;
    for(int i = 0; i < n; i++)
    {
        g = __gcd(g, arr[i]);
        have[i] = g;
    }

    int i = n - 1;
    g = 1;
    while(i >= 0)
    {
        int ng = have[i] / g;
        pi val = get(ng);
        int me = (-val.ff + val.ss) * (i + 1);
        if(me >= 0)
            ans += me, g *= ng;
        i--;
    }

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

