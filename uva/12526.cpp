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

const int MAX_CHAR = 26;
const char base = 'a';
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

    int dfs(const string &s, int idx = 0)
    {
        if(idx == ln(s))
            return 0;

        int c = s[idx] - base;

        if(child[c] == 0)
            return ln(s) - idx;

        int cnt = 0;
        for(int i = 0; i < MAX_CHAR; i++)
            if(child[i])
                cnt++;

        int cost = (cnt > 1) | isLeaf;
        if(idx == 0)
            cost = 1;
        return cost + child[c]->dfs(s, idx + 1);
    }
};

void cp(int n)
{
    vector<string> arr(n);
    for(string &x : arr)
        cin >> x;

    trie *root = new trie;
    for(string &x : arr)
        root->insert(x);

    double avg = 0;
    for(string &x : arr)
    {
        int me = root->dfs(x);
        avg += me;
    }
    avg /= n;
    cout << avg << endl;
}

int main()
{
    FASTIO;
    dblout(2);
    int t;
    t = 1;
    while(cin >> t)
    {
        cp(t);
    }
    return 0;
}