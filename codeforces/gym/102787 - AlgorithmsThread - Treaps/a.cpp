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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;


/*
	Treap / Cartesian Tree
	For unordered array / unsorted

	Operations -
	1. Insert
	2. Erase
	3. Split
	4. Merge
	5. Build
	6. Search
	7. Range Query
	8. Range Update
	9. Range reversal (special range update)

	Customise -

	Initialization -
	Treap *root = NULL;

	Gotchas -
	1. Push changes before making changes to or using value of a node
	2. After making changes, pull the node
*/

struct Treap
{
    int val, priority;
    int lazy, reversal, subtreeSize;
    array<Treap *, 2> child;

    Treap()
    {
        child = {NULL, NULL};
        val = 0, lazy = 0, reversal = 0, subtreeSize = 0;
        priority = 0;
    }
    Treap(int _val)
    {
        child = {NULL, NULL};
        val = _val, lazy = 0, reversal = 0, subtreeSize = 1;
        priority = rand(0, 1000000000);
    }
};

int size(Treap *root)
{
    return root == NULL ? 0 : root->subtreeSize;
}

void pull(Treap *root)
{
    if(root == NULL) return;
    // calculate values of root using its children
    root->subtreeSize = 1;
    for(auto c : root->child) if(c != NULL) root->subtreeSize += c->subtreeSize;
}

void push(Treap *root)
{
    if(root == NULL) return;
    // push lazy prop update to children
    if(root->reversal) swap(root->child[0], root->child[1]);
    for(auto c : root->child) if(c != NULL) c->reversal ^= root->reversal;
    root->reversal = 0;
}

Treap *merge(Treap *l, Treap *r)
{
    if(l == NULL) return r;
    if(r == NULL) return l;
    push(l), push(r);
    if(l->priority < r->priority)
    {
        l->child[1] = merge(l->child[1], r);
        pull(l);
        return l;
    }
    else
    {
        r->child[0] = merge(l, r->child[0]);
        pull(r);
        return r;
    }
}

array<Treap *, 2> split(Treap *root, int szLeft)
{
    if(root == NULL) return {NULL, NULL};
    push(root);
    if(size(root->child[0]) >= szLeft)
    {
        auto leftRes = split(root->child[0], szLeft);
        root->child[0] = leftRes[1];
        pull(root);
        return {leftRes[0], root};
    }
    else
    {
        szLeft = szLeft - size(root->child[0]) - 1;
        auto rightRes = split(root->child[1], szLeft);
        root->child[1] = rightRes[0];
        pull(root);
        return {root, rightRes[1]};
    }
}

Treap *reverse(Treap *root, int l, int r) // reverse subarray [l, r]
{
    if(root == NULL) return root;

    assert(l <= r);
    int n = root->subtreeSize;

    auto leftRes = split(root, l);
    auto L = leftRes[0];
    root = leftRes[1];

    auto rightRes = split(root, r - l + 1);
    root = rightRes[0];
    auto R = rightRes[1];

    root->reversal ^= 1;
    return merge(L, merge(root, R));
}

void dfs(Treap *root)
{
    if(root == NULL) return;
    push(root);
    dfs(root->child[0]);
    cout << root->val << " ";
    dfs(root->child[1]);
}

void cp()
{
    int n;
    cin >> n;

    Treap *root = NULL;
    for(int i = 1; i <= n; i++)
        root = merge(root, new Treap(i));

    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l >= r) continue;
        int sz = min(r - l, n - r);
        // [l, l+sz-1] [r, r+sz-1]
        auto S = split(root, l);
        auto A = S[0];
        root = S[1];
        S = split(root, sz);
        auto B = S[0];
        root = S[1];
        S = split(root, r - (l + sz - 1) - 1);
        auto C = S[0];
        root = S[1];
        S = split(root, sz);
        auto D = S[0];
        root = S[1];
        // ABCDroot
        swap(B, D);
        root = merge(D, root);
        root = merge(C, root);
        root = merge(B, root);
        root = merge(A, root);
    }
    dfs(root);
    cout << endl;
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
