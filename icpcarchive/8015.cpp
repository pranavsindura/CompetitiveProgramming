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
const int MAXN = 1e6 + 5;

vector<string> a;

const int MAX_CHAR = 26;
const char base = 'a';
struct trie
{
    trie *child[MAX_CHAR];
    int subtree;

    trie()
    {
        clr(child, 0);
        subtree = 0;
    }

    void insert(const string &s, int idx = 0)
    {
        if(idx < ln(s))
        {
            int c = s[idx] - base;
            if(!child[c])
                child[c] = new trie();
            child[c]->insert(s, idx + 1);
            child[c]->subtree++;
        }
    }

    bool check(const string &s, int max_depth, int idx = 0)
    {
        if(idx < max_depth)
        {
            int need = max_depth - idx;
            int c = s[idx] - base;
            if(child[c])
            {
                if(child[c]->subtree < need)
                    return false;
                else
                    return child[c]->check(s, max_depth, idx + 1);
            }
            else
                return false;
        }
        else
            return true;
    }

    void clear()
    {
        for(int i = 0; i < MAX_CHAR; i++)
        {
            if(child[i])
            {
                child[i]->clear();
                delete child[i];
            }
        }
    }
};

void cp()
{
    int n, m;
    while(cin >> n >> m)
    {
        a.resize(n);
        for(string &x : a)
            cin >> x;

        trie *root = new trie();
        string s;
        for(int i = 0; i < m; i++)
        {
            cin >> s;
            root->insert(s);
        }

        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            int lo = 1, hi = sz(a[i]);
            int can = 0;
            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;
                bool ok = root->check(a[i], mid);
                if(ok)
                    can = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            sum += can;
        }
        cout << sum << endl;
        root->clear();
        delete root;
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