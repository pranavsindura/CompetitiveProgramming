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

vector<int> ans;

const int MAX_CHAR = 26;
const char base = 'a';
struct trie
{
    trie *child[MAX_CHAR];
    bool isLeaf;
    int key;
    trie()
    {
        clr(child, 0);
        isLeaf = 0;
        key = -1;
    }
    void insert(const string &s, int my_key, int idx = 0)
    {
        if(idx == ln(s))
            isLeaf = 1, key = my_key;
        else
        {
            int c = s[idx] - base;
            if(child[c] == 0)
                child[c] = new trie;
            child[c]->insert(s, my_key, idx + 1);
        }
    }

    void dfs(const string &s, int idx = 0)
    {

        if(idx >= ln(s))
        {
            if(isLeaf && idx != ln(s))
                ans.pb(key);

            for(int i = 0; i < MAX_CHAR; i++)
                if(child[i])
                    child[i]->dfs(s, idx + 1);
        }
        else
        {
            int c = s[idx] - base;
            if(child[c])
                child[c]->dfs(s, idx + 1);
        }
    }
};

void cp()
{
    int n, q;
    cin >> n;

    vector<string> arr;
    string s;
    trie *root = new trie();

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        arr.pb(s);
        root->insert(s, i);
    }

    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> s;
        ans.clear();
        root->dfs(s);
        cout << "Case #" << i << ":\n";
        if(ans.empty())
            cout << "No match.\n";
        else
            for(int idx : ans)
                cout << arr[idx] << endl;
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