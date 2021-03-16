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
const int MAXN = 6e5 + 5;


array<ll, MAXN> P;
const ll HMOD = 1e9 + 9;
void init_hash()
{
    P[0] = 1;
    for(int i = 1; i < MAXN; i++)
        P[i] = (P[i - 1] * 31) % HMOD;
}

/*
	Treap / Cartesian Tree

	For array / non BST

	Operations -
	1. Insert          X
	2. Erase
	3. Split
	4. Merge
	5. Build           X
	6. Search          X
	7. Range Query
	8. Range Update
	9. Range reversal (special range update)

	Customise -
	push()
	pull()
	Data in Treap node
	Treap(data)

	Initialization -

	Treap *root = NULL;

	Merge numbers one after another to form the treap for array

	Gotchas -
	1. Push changes before making changes to or using value of a node
	2. After making changes, pull the node
*/

struct Treap
{
    int priority, reversal, subtreeSize;
    array<Treap *, 2> child;

    // Data
    char data;
    ll pref, suff;
    int lazy;

    Treap(char);
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

    root->pref = 0;
    if(root->child[0])
        root->pref = root->child[0]->pref;
    root->pref = (root->pref + (root->data - '0' + 1) * P[size(root->child[0])]) % HMOD;
    if(root->child[1])
        root->pref = (root->pref + (root->child[1]->pref * P[size(root->child[0]) + 1]) % HMOD) % HMOD;

    root->suff = 0;
    if(root->child[1])
        root->suff = root->child[1]->suff;
    root->suff = (root->suff + (root->data - '0' + 1) * P[size(root->child[1])]) % HMOD;
    if(root->child[0])
        root->suff = (root->suff + (root->child[0]->suff * P[size(root->child[1]) + 1]) % HMOD) % HMOD;
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

Treap::Treap(char _data)
{
    child = {NULL, NULL};
    reversal = 0, subtreeSize = 1;
    priority = rand(0, 1000000000);

    data = _data;
    lazy = 0;
}

void dfs(Treap *root)
{
    if(root == NULL) return;
    push(root);
    dfs(root->child[0]);
    cout << root->data;
    dfs(root->child[1]);
}

void clean(Treap *root)
{
    if(root == NULL) return;
    clean(root->child[0]);
    clean(root->child[1]);
    delete root;
}

void cp()
{
    int n, q;
    string s;
    cin >> n >> q >> s;

    Treap *root = NULL;
    for(char x : s)
        root = merge(root, new Treap(x));

    while(q--)
    {
        int t, l, r;
        char c;
        cin >> t;
        if(t == 1 || t == 3) cin >> l >> r;
        else cin >> c >> l;

        if(t == 1)
        {
            l--, r--;
            auto S = split(root, l);
            auto L = S[0];
            root = S[1];
            S = split(root, r - l + 1);
            root = S[0];
            auto R = S[1];

            // L root R
            clean(root);
            root = merge(L, R);
        }
        else if(t == 2)
        {
            l--;
            auto S = split(root, l);
            root = merge(S[0], merge(new Treap(c), S[1]));
        }
        else
        {
            l--, r--;
            auto S = split(root, l);
            auto L = S[0];
            root = S[1];
            S = split(root, r - l + 1);
            root = S[0];
            auto R = S[1];

            // L root R
            // Split root in half
            bool ok = false;
            int split_size = (r - l + 1) / 2;
            if((r - l + 1) & 1)
            {
                S = split(root, split_size);
                auto X = S[0];
                root = S[1];
                S = split(root, 1);
                root = S[0];
                auto Y = S[1];
                // X root Y
                if(size(X) == 0) // and size(X) == size(Y)
                    ok = true;
                else
                    ok = X->pref == Y->suff;
                root = merge(X, merge(root, Y));
            }
            else
            {
                S = split(root, split_size);
                auto X = S[0];
                auto Y = S[1];
                // X Y
                ok = X->pref == Y->suff;
                root = merge(X, Y);
            }

            root = merge(L, merge(root, R));
            cout << (ok ? "yes\n" : "no\n");
        }
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init_hash();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
