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
const int MAXN = 1e3 + 5;

int n, m;
string a[MAXN], b[MAXN];

ll total_suff, ans;

const int MAX_CHAR = 26;
const char base = 'a';
int suff_count[MAX_CHAR], direct_root[MAX_CHAR];
struct trie
{
    trie *child[MAX_CHAR];

    trie()
    {
        clr(child, 0);
    }

    void insert_suff(const string &s, int idx = 0)
    {
        if(idx < ln(s))
        {
            int c = s[idx] - base;
            if(child[c] == 0)
            {
                child[c] = new trie();
                suff_count[c]++;
                direct_root[c] += (idx == 0);
            }

            child[c]->insert_suff(s, idx + 1);
        }
    }

    void insert_pref(const string &s, int idx = 0)
    {
        if(idx < ln(s))
        {
            int c = s[idx] - base;
            if(child[c] == 0)
            {
                child[c] = new trie();

                ll adding = total_suff;
                if(idx)
                    adding -= suff_count[c] - direct_root[c];
                ans += adding;
            }

            child[c]->insert_pref(s, idx + 1);
        }
    }
};

void cp()
{
    while(cin >> n >> m && n + m)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];

        clr(suff_count, 0);
        clr(direct_root, 0);
        total_suff = ans = 0;

        trie *pref = new trie, *suff = new trie;

        for(int i = 0; i < m; i++)
        {
            reverse(all(b[i]));
            suff->insert_suff(b[i]);
        }

        for(int i = 0; i < MAX_CHAR; i++)
            total_suff += suff_count[i];

        for(int i = 0; i < n; i++)
            pref->insert_pref(a[i]);

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