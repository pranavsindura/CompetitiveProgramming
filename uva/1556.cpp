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

struct trie
{
    map<string, trie *> child;
    trie() {}
    void insert(const vector<string> &s, int idx = 0)
    {
        if(idx < sz(s))
        {
            if(!child.count(s[idx]))
                child[s[idx]] = new trie();
            child[s[idx]]->insert(s, idx + 1);
        }
    }
    void dfs(int depth = 0)
    {
        for(auto &x : child)
        {
            cout << string(depth, ' ') << x.ff << endl;
            x.ss->dfs(depth + 1);
        }
    }
};

void cp(int n)
{
    trie *root = new trie;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(char &x : s)
            if(x == '\\')
                x = ' ';
        stringstream ss(s);
        string x;
        vector<string> inp;
        while(ss >> x)
            inp.pb(x);
        root->insert(inp);
    }
    root->dfs();
    cout << endl;
}

int main()
{
    FASTIO;
    int n;

    while(cin >> n)
    {
        cp(n);
    }
    return 0;
}