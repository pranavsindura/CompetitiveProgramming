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
const int MAXN = 1e5 + 5;

const int MAX_DEPTH = 50; // number of bits
struct trie
{
    array<trie *, 2> child;
    bool isLeaf;
    int subtree;

    trie()
    {
        child = {NULL, NULL};
        isLeaf = 0, subtree = 0;
    }

    void insert(ll s, int idx = MAX_DEPTH)
    {
        if(idx < 0)
            isLeaf = 1, subtree++;
        else
        {
            int c = (s >> idx) & 1LL;
            if(child[c] == 0) child[c] = new trie;
            child[c]->insert(s, idx - 1);
            subtree = 0;
            if(child[0]) subtree += child[0]->subtree;
            if(child[1]) subtree += child[1]->subtree;
        }
    }

    void erase(ll s, int qty, int idx = MAX_DEPTH)
    {
        if(idx < 0)
            assert(subtree >= qty), subtree -= qty, isLeaf = subtree > 0;
        else
        {
            int c = (s >> idx) & 1;
            if(child[c]) child[c]->erase(s, qty, idx - 1);
            else assert(false);
            if(child[c]->subtree == 0)
            {
                delete child[c];
                child[c] = NULL;
            }

            subtree = 0;
            if(child[0]) subtree += child[0]->subtree;
            if(child[1]) subtree += child[1]->subtree;
        }
    }

    // Z s.t. s XOR Z is max
    ll max_xor(ll s, int idx = MAX_DEPTH)
    {
        if(idx < 0) return 0;
        ll c = (s >> idx) & 1;
        if(child[c ^ 1]) return child[c ^ 1]->max_xor(s, idx - 1) | ((c ^ 1) << idx);
        else if(child[c]) return child[c]->max_xor(s, idx - 1) | (c << idx);
        else assert(false);
    }
};

void cp()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;

    vector<ll> suff(n);
    suff[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] ^ arr[i];

    trie *root = new trie;
    for(ll x : suff) root->insert(x);
    root->insert(0);

    ll ans = root->max_xor(0), pref = 0;
    for(int i = 0; i < n; i++)
    {
        pref ^= arr[i];
        root->erase(suff[i], 1);
        ans = max(ans, pref ^ root->max_xor(pref));
    }
    cout << ans << endl;
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
