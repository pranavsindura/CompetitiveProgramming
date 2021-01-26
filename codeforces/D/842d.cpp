#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1 << 19;

bool exist[MAXN];

struct trie
{
    trie *child[2];
    int val;
    trie()
    {
        clr(child, 0);
        val = 0;
    }

    void insert(int n, int depth = 20)
    {
        if(depth < 0)
            val = n;
        else
        {
            int b = (n >> depth) & 1;
            if(!child[b])
                child[b] = new trie();
            child[b]->insert(n, depth - 1);
        }
    }

    int dfs(int n, int depth = 20)
    {
        if(depth < 0)
            return val;
        else
        {
            int b = (n >> depth) & 1;
            if(child[b])
                return child[b]->dfs(n, depth - 1);
            else
                return child[b ^ 1]->dfs(n, depth - 1);
        }
    }
};

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0, x; i < n; i++)
        cin >> x, exist[x] = 1;

    trie *root = new trie();

    for(int i = 0; i < MAXN; i++)
        if(!exist[i])
            root->insert(i);

    int val = 0;
    while(q--)
    {
        int x;
        cin >> x;
        val ^= x;
        int best = root->dfs(val);
        int ans = best ^ val;
        cout << ans << endl;
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