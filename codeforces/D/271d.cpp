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

    int insert(const string &s, int i, int j)
    {
        int create = 0;
        if(i > j)
            isLeaf = 1;
        else
        {
            int c = s[i] - base;
            if(child[c] == 0)
                child[c] = new trie, create++;
            create += child[c]->insert(s, i + 1, j);
        }
        return create;
    }
};

void cp()
{
    string s, t;
    int k;
    cin >> s >> t >> k;

    int n = ln(s);
    int ans = 0;

    trie *root = new trie;

    for(int i = 0; i < n; i++)
    {
        int j = i;
        int cnt = (t[s[i] - 'a'] == '0');
        if(cnt > k)
            continue;
        while(j + 1 < n && cnt + (t[s[j + 1] - 'a'] == '0') <= k)
            cnt += (t[s[j + 1] - 'a'] == '0'), j++;
        //s[i....j]
        ans += root->insert(s, i, j);
    }
    cout << ans << endl;
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