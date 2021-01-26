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
const int MAXN = 2e5 + 5;

struct trie
{
    trie *child[2];
    bool isLeaf;
    int val;

    trie()
    {
        clr(child, 0);
        isLeaf = 0;
        val = 0;
    }

    void insert(int n, int depth = 30)
    {
        if(depth < 0)
            isLeaf = 1, val = n;
        else
        {
            int c = (n >> depth) & 1;
            if(child[c] == 0)
                child[c] = new trie();
            child[c]->insert(n, depth - 1);
        }
    }
    int dfs()
    {
        if(isLeaf)
            return 1;
        else if(!child[0])
            return child[1]->dfs();
        else if(!child[1])
            return child[0]->dfs();
        else
            return 1 + max(child[0]->dfs(), child[1]->dfs());
    }
};

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    trie *root = new trie;
    for(int x : arr)
        root->insert(x);

    cout << n - root->dfs() << endl;
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