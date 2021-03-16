
/*
    Treap / Cartesian Tree

    For array / non BST

    Operations -
    1. Insert          X
    2. Erase
    3. Split
    4. Merge
    5. Build           X Merge sequentially
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

using ftype = int;
struct Treap
{
    int priority, reversal, subtreeSize;
    array<Treap *, 2> child;

    // Data
    ftype data;
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
    root->subtreeSize = 1;
    for(auto c : root->child) if(c != NULL) root->subtreeSize += c->subtreeSize;

}

// CHANGE
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

// CHANGE
Treap::Treap(ftype _data)
{
    child = {NULL, NULL};
    reversal = 0, subtreeSize = 1;
    priority = rand(0, 1000000000);

    data = _data;
    lazy = 0;

    pull(this);
}





// Range Reversal
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





// Inorder Traversal
void dfs(Treap *root, int depth = 0)
{
    if(root == NULL) return;
    push(root);
    dfs(root->child[0], depth + 1);
    cout << "(" << root->data << "," << root->priority << ") ";
    dfs(root->child[1], depth + 1);
}






// Delete a node and its children
void clean(Treap *root)
{
    if(root == NULL) return;
    clean(root->child[0]);
    clean(root->child[1]);
    delete root;
}
