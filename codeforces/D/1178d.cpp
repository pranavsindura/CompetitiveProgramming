#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 2e3 + 5;

vector<int> prime;
bool is_prime[MAXN];
void init()
{
    is_prime[1] = false;
    clr(is_prime, true);
    for(int i = 2; i < MAXN; i++)
    {
        if(is_prime[i])
            prime.pb(i);
        for(int j = 0; j < sz(prime) && i * prime[j] < MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
}

void cp()
{
    int n;
    cin >> n;

    // Ring, force degree 2
    vector<vector<int>> edges;
    for(int i = 1; i <= n; i++)
        edges.pb({i, i + 1});
    edges.back()[1] = 1;

    // Join every node with skip 3 node, to add edges, force degree 3 of both nodes
    // there are n/2 such more edges, should be sufficient to make the total edges prime
    int p = *lower_bound(all(prime), n);
    int e = p - n;
    int st = 1;
    while(e--)
    {
        int u = st, v = (st - 1 + 2 + n) % n + 1;
        edges.pb({u, v});
        if(e)
        {
            e--;
            u++, v++;
            edges.pb({u, v});
            st = (st - 1 + 4 + n) % n + 1;
        }
    }
    cout << sz(edges) << endl;
    for(auto v : edges)
        cout << v[0] << " " << v[1] << endl;
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

