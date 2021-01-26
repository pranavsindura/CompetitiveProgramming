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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

const int MAX_CHAR = 2;
const int base = 0;
struct trie
{
    trie *child[MAX_CHAR];
    bool isLeaf;
    int freq;

    trie()
    {
        clr(child, 0);
        isLeaf = 0;
        freq = 0;
    }

    void insert(int n, int depth = 31)
    {
        if(depth < 0)
            isLeaf = 1, freq++;
        else
        {
            int c = (n >> depth) & 1;
            if(child[c] == 0)
                child[c] = new trie();
            child[c]->insert(n, depth - 1);
        }
    }

    bool remove(int n, int depth = 31)
    {
        if(depth < 0)
        {
            freq--;
            isLeaf = (freq > 0);
            return !isLeaf;
        }
        else
        {
            int c = (n >> depth) & 1;
            bool should_remove = child[c]->remove(n, depth - 1);

            if(should_remove)
                delete child[c], child[c] = 0;

            return !(child[0] || child[1]);
        }
    }

    int dfs(int n, int depth = 31)
    {
        if(isLeaf)
            return 0;

        int ans = 0;
        int bit = (n >> depth) & 1;
        if(bit)
        {
            // pick zero
            if(child[0])
                ans = (1 << depth) + child[0]->dfs(n, depth - 1);
            else if(child[1])
                ans = child[1]->dfs(n, depth - 1);
        }
        else
        {
            // pick one
            if(child[1])
                ans = (1 << depth) + child[1]->dfs(n, depth - 1);
            else if(child[0])
                ans = child[0]->dfs(n, depth - 1);
        }
        return ans;
    }
};

void cp()
{
    int q;
    cin >> q;

    trie *root = new trie();

    root->insert(0);

    while(q--)
    {
        char t;
        int x;
        cin >> t >> x;
        if(t == '+')
            root->insert(x);
        else if(t == '-')
            root->remove(x);
        else
            cout << root->dfs(x) << endl;
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