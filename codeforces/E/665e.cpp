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

/*
	For each 0 bit in k, we can place a 1 here and the remaining bits can be X (dont care)
	and the subrarrays having this mask will have xor > k
	TLE, because of extra log and high constant
	O(30 * n * logn)

	We can try to replace the map with a trie + subtree sum and reinterpret the problem
	Should be O(n * 30) now

	xorpref[i] ^ xorpref[j] >= k
	fixed        find this     fixed

	put all xorpref[i] into a trie
	for each bit, we can break it into cases to appropriately find xorpref[j] and its count
*/

struct trie
{
    ll sum;
    trie *child[2];

    trie()
    {
        clr(child, 0);
        sum = 0;
    }

    void insert(ll num, int depth = 30)
    {
        if(depth < 0)
            sum++;
        else
        {
            int b = (num >> depth) & 1;
            if(child[b] == 0)
                child[b] = new trie;
            child[b]->insert(num, depth - 1);
            sum = (child[0] ? child[0]->sum : 0) + (child[1] ? child[1]->sum : 0);
        }
    }

    ll dfs(ll pref, ll k, int depth = 30)
    {
        if(depth < 0)
            return sum;

        int kb = (k >> depth) & 1;
        int pb = (pref >> depth) & 1;

        if(kb)
            return child[pb ^ 1] ? child[pb ^ 1]->dfs(pref, k, depth - 1) : 0;
        else
            return (child[pb ^ 1] ? child[pb ^ 1]->sum : 0) + (child[pb] ? child[pb]->dfs(pref, k, depth - 1) : 0);
    }
};

array<ll, MAXN> arr;

void cp()
{
    int n;
    ll k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    trie *root = new trie;
    root->insert(0);

    ll ans = 0;
    int pref = 0;
    for(int i = 0; i < n; i++)
    {
        pref ^= arr[i];
        ans += root->dfs(pref, k);
        root->insert(pref);
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