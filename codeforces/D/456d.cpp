#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

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

    bool solve_win(int p, int d)
    {
        bool last = true, can = false;
        for(int i = 0; i < MAX_CHAR; i++)
        {
            if(!child[i]) continue;
            last = false;
            can |= !child[i]->solve_win(p ^ 1, d + 1);
        }
        if(last)
        {
            if((d - 1) % 2 == 0) can = p == 1;
            else can = p == 0;
        }
        return can;
    }

    bool solve_lose(int p, int d)
    {
        bool last = true, can = false;
        for(int i = 0; i < MAX_CHAR; i++)
        {
            if(!child[i]) continue;
            last = false;
            can |= !child[i]->solve_lose(p ^ 1, d + 1);
        }
        if(last)
        {
            if((d - 1) % 2 == 0) can = p == 0;
            else can = p == 1;
        }
        return can;
    }
};

void cp()
{
    int n, k;
    cin >> n >> k;

    trie *root = new trie();
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        root->insert(s);
    }

    bool can_win = root->solve_win(0, 1);
    bool can_lose = root->solve_lose(0, 1);

    if(can_lose && can_win)
        cout << "First\n";
    else if(can_lose)
        cout << "Second\n";
    else if(can_win)
        cout << (k % 2 ? "First\n" : "Second\n");
    else
        cout << "Second\n";
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
