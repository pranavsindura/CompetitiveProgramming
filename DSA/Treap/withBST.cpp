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
