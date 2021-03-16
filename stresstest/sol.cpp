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
const int MAXN = 3e6 + 5;

/*
    Treap / Cartesian Tree

    Actual Heap + BST

    Operations -
    1. Insert
    2. Erase
    3. Split
    4. Merge
    5. Build           X Insert sequentially
    6. Search
    7. Range Query
    8. Range Update

    Customise -
    push()
    pull()
    Data in Treap node
    Treap(data)

    Initialization -

    Treap *root = NULL;

    Merge numbers one after another to form the treap

    Gotchas -
    1. Push changes before making changes to or using value of a node
    2. After making changes, pull the node
*/

using ftype = int; // Define < if custom
struct Treap
{
    int priority, subtreeSize;
    array<Treap *, 2> child;

    ftype data;
    int freq;
    int lazy;

    Treap(ftype);
};

int size(Treap *root)
{
    return root == NULL ? 0 : root->subtreeSize;
}

// CHANGE
void pull(Treap *root)
{
    if(root == NULL) return;
    // calculate values of root using its children
    root->subtreeSize = root->freq;
    for(auto &c : root->child) if(c != NULL) root->subtreeSize += c->subtreeSize;

}

// CHANGE
void push(Treap *root)
{
    if(root == NULL) return;
    // push lazy prop update to children

}

Treap *merge(Treap *l, Treap *r) // Assumes l and r are ordered, i.e. all elements in l < r
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

array<Treap *, 2> split(Treap *root, ftype key) // All elements <= key in left
{
    if(root == NULL) return {NULL, NULL};
    push(root);
    if(key < root->data)
    {
        auto leftRes = split(root->child[0], key);
        root->child[0] = leftRes[1];
        pull(root);
        return {leftRes[0], root};
    }
    else
    {
        auto rightRes = split(root->child[1], key);
        root->child[1] = rightRes[0];
        pull(root);
        return {root, rightRes[1]};
    }
}

Treap *insert(Treap *root, Treap *node) // assumes only unique items will be inserted, otherwise you can search and then point update
{
    if(root == NULL) return node;
    push(root);
    if(root->priority > node->priority)
    {
        auto S = split(root, node->data);
        node->child[0] = S[0];
        node->child[1] = S[1];
        pull(node);
        return node;
    }
    else if(root->data < node->data)
    {
        auto r = insert(root->child[1], node);
        root->child[1] = r;
        pull(root);
        return root;
    }
    else if(root->data > node->data)
    {
        auto l = insert(root->child[0], node);
        root->child[0] = l;
        pull(root);
        return root;
    }
    else
    {
        root->freq++;
        pull(root);
        return root;
    }
}

Treap *remove(Treap *root, Treap *node)
{
    if(root == NULL) return NULL;
    push(root);
    if(root->data < node->data)
    {
        auto r = remove(root->child[1], node);
        root->child[1] = r;
        pull(root);
        return root;
    }
    else if(root->data > node->data)
    {
        auto l = remove(root->child[0], node);
        root->child[0] = l;
        pull(root);
        return root;
    }
    else
    {
        root->freq--;
        pull(root);
        if(root->freq == 0) root = merge(root->child[0], root->child[1]);
        pull(root);
        return root;
    }
}

Treap *search(Treap *root, ftype key) // Search as normal BST
{
    if(root == NULL) return NULL;
    push(root);
    if(root->data == key) return root;
    else if(root->data < key) return search(root->child[1], key);
    else return search(root->child[0], key);
}

Treap *kth_one(Treap *root, int k) // Search as normal BST using subtree size
{
    if(root == NULL) return NULL;
    push(root);

    if(size(root) < k) return NULL;

    if(size(root->child[0]) >= k) return kth_one(root->child[0], k);
    else if(size(root->child[0]) + root->freq >= k) return root;
    else return kth_one(root->child[1], k - (size(root->child[0]) + root->freq));
}

// CHANGE
Treap::Treap(ftype _data)
{
    child = {NULL, NULL};
    subtreeSize = 1;
    priority = rand(0, 1000000000);

    data = _data;
    freq = 1;
    lazy = 0;

    pull(this);
}

void dfs(Treap *root, int depth = 0)
{
    if(root == NULL) return;
    push(root);
    dfs(root->child[0], depth + 1);
    cout << "(" << root->data << "," << root->freq << "," << root->subtreeSize << ") "; // << root->priority << ") ";
    dfs(root->child[1], depth + 1);
}

void cp()
{
    int T, X;
    Treap *root = NULL;
    while(cin >> T && ~T)
    {
        cin >> X;
        if(T == 1)
        {
            root = insert(root, new Treap(X));
        }
        else if(T == 2)
        {
            root = remove(root, new Treap(X));
        }
        else if(T == 3)
        {
            if(search(root, X))
            {
                auto S = split(root, X - 1);
                cout << size(S[0]) + 1 << endl;
                root = merge(S[0], S[1]);
            }
            else
                cout << -1 << endl;
        }
        else
        {
            if(X == 0) cout << -1 << endl;
            else
            {
                auto V =  kth_one(root, X);
                if(V == NULL) cout << -1 << endl;
                else cout << V->data << endl;
            }
        }
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
