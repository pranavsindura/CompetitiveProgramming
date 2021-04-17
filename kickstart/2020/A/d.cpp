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

// Bundling

const int MAX_CHAR = 26;
const char base = 'A';
struct trie
{
    trie *child[MAX_CHAR];
    bool isLeaf;
    int subtree;

    trie()
    {
        clr(child, 0);
        isLeaf = subtree = 0;
    }

    void insert(const string &s, int idx = 0)
    {
        if(idx == ln(s))
            isLeaf = 1;
        else
        {
            int c = s[idx] - base;
            if(child[c] == 0) child[c] = new trie;
            child[c]->insert(s, idx + 1);
        }
        subtree++;
    }

    void clean()
    {
        for(int i = 0; i < MAX_CHAR; i++)
            if(child[i])
            {
                child[i]->clean();
                delete child[i];
            }
    }

    array<ll, 2> dfs(int k, int depth = 0)
    {
        ll ans = 0, rem = subtree;
        for(int i = 0; i < MAX_CHAR; i++)
            if(child[i])
            {
                auto c = child[i]->dfs(k, depth + 1);
                ans += c[0], rem -= c[1];
            }
        ans += (rem / k) * depth;
        rem %= k;
        return {ans, subtree - rem};
    }

};


void cp()
{
    int n, k;
    cin >> n >> k;
    trie *root = new trie;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        root->insert(s);
    }

    auto ans = root->dfs(k);
    cout << ans[0] << endl;
    assert(ans[1] == n);
    root->clean();
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}
