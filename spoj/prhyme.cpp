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
const int MAXN = 3e5 + 5;

string arr[MAXN];
int ans, curkey;

const int MAX_CHAR = 26;
const char base = 'a';
struct trie
{
    trie *child[MAX_CHAR];
    int key, mnkey;
    bool isLeaf;

    trie()
    {
        clr(child, 0);
        key = mnkey = INT_MAX;
        isLeaf = 0;
    }

    void insert(const string &s, int mykey, int idx = 0)
    {
        if(idx == ln(s))
        {
            isLeaf = 1;
            key = mykey;
            mnkey = min(mnkey, mykey);
        }
        else
        {
            int c = s[idx] - base;
            if(child[c] == 0)
                child[c] = new trie();
            child[c]->insert(s, mykey, idx + 1);
            mnkey = min(mnkey, child[c]->mnkey);
        }
    }

    void dfs(const string &s, const string &rev, int idx = 0)
    {
        if(idx < ln(s))
        {
            // match char
            int c = s[idx] - base;
            if(child[c])
                child[c]->dfs(s, rev, idx + 1);

            if(ans != INT_MAX)
                return;
        }

        if(arr[mnkey] != rev)
            ans = min(ans, mnkey);

        if(isLeaf && arr[key] != rev)
            ans = min(ans, key);

        for(int i = 0; i < MAX_CHAR; i++)
            if(child[i] && arr[child[i]->mnkey] != rev)
                ans = min(ans, child[i]->mnkey);
    }

};

void cp()
{
    int n = 0;
    string s, rev;
    trie *root = new trie();

    while(getline(cin, s) && !s.empty())
        arr[n++] = s;

    sort(arr, arr + n);

    for(int i = 0; i < n; i++)
    {
        s = arr[i];
        reverse(all(s));
        root->insert(s, i);
    }

    while(getline(cin, s) && !s.empty())
    {
        rev = s;
        reverse(all(rev));
        ans = INT_MAX;
        root->dfs(rev, s);
        if(ans != INT_MAX)
        {
            s = arr[ans];
            cout << s << endl;
        }
        else
            while(1);
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