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

const int MAX_CHAR = 10;
const char base = '0';
struct trie
{
    trie *child[MAX_CHAR];
    bool isLeaf;

    trie()
    {
        clr(child, 0);
        isLeaf = 0;
    }

    void insert(const string &s, int idx = 0)
    {
        if(idx == ln(s))
            isLeaf = 1;
        else
        {
            int c = s[idx] - base;
            if(child[c] == 0)
                child[c] = new trie;
            child[c]->insert(s, idx + 1);
        }
    }

    bool dfs()
    {
        bool ok = true;
        bool anychild = false;
        for(int i = 0; i < MAX_CHAR; i++)
            if(child[i])
                ok &= child[i]->dfs(), anychild = true;
        if(anychild && isLeaf)
            ok = false;
        return ok;
    }
};

void cp()
{
    int n;
    cin >> n;
    trie *root = new trie;
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;
    for(string &s : arr)
        root->insert(s);
    bool ok = root->dfs();
    cout << (ok ? "YES\n" : "NO\n");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}