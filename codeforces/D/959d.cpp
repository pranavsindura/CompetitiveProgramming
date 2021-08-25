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
const int MAXN = 1e7 + 5;

// Smallest Prime Factor
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

bool allowed[MAXN];
void exclude(int n)
{
    while(n > 1)
    {
        int x = lp[n];
        n /= x;
        if(!allowed[x]) continue;
        for(int i = x; i < MAXN; i += x)
            allowed[i] = false;
    }
}

int mex;
void get_mex()
{
    while(mex < MAXN && !allowed[mex]) mex++;
    assert(mex < MAXN);
}

void cp()
{
    sieve();

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    clr(allowed, true);
    allowed[0] = allowed[1] = false;

    bool started = false;
    vector<int> ans;
    for(int x : arr)
    {
        if(allowed[x] && !started)
        {
            ans.push_back(x);
            exclude(x);
        }
        else
        {
            if(!started) mex = max(mex, x);
            get_mex();
            ans.push_back(mex);
            exclude(mex);
            if(!started) mex = 0;
            started = true;
        }
    }

    for(int x : ans)
        cout << x << " ";
    cout << endl;
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
