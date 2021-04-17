// Simple Trie Format
// Fixed array of children
// For more complicated Trie, we can use a map of char->trie ptr, or string->trie ptr

const int MAX_CHAR = 26;
const char base = 'a';
struct trie
{
    trie *child[MAX_CHAR];
    bool isLeaf;
    int subtree;

    trie()
    {
        clr(child, 0);
        isLeaf = subtree = 0;
    }

    void insert(const string &s, int idx = 0)
    {
        if(idx == ln(s))
            isLeaf = 1;
        else
        {
            int c = s[idx] - base;
            if(child[c] == 0) child[c] = new trie;
            child[c]->insert(s, idx + 1);
        }
        subtree++;
    }

    void clean()
    {
        for(int i = 0; i < MAX_CHAR; i++)
            if(child[i])
            {
                child[i]->clean();
                delete child[i];
            }
    }

    void dfs()
    {

    }
};



// For Numbers - Bit representation
const int MAX_DEPTH = 20; // number of bits
struct trie
{
    array<trie *, 2> child;
    bool isLeaf;
    int subtree;

    trie()
    {
        child = {NULL, NULL};
        isLeaf = 0, subtree = 0;
    }

    void insert(int s, int idx = MAX_DEPTH)
    {
        if(idx < 0)
            isLeaf = 1, subtree++;
        else
        {
            int c = (s >> idx) & 1;
            if(child[c] == 0) child[c] = new trie;
            child[c]->insert(s, idx - 1);
            subtree = 0;
            if(child[0]) subtree += child[0]->subtree;
            if(child[1]) subtree += child[1]->subtree;
        }
    }
    void erase(int s, int qty, int idx = MAX_DEPTH)
    {
        if(idx < 0)
            assert(subtree >= qty), subtree -= qty, isLeaf = subtree > 0;
        else
        {
            int c = (s >> idx) & 1;
            if(child[c]) child[c]->erase(s, qty, idx - 1);
            else assert(false);
            if(child[c]->subtree == 0)
            {
                delete child[c];
                child[c] = NULL;
            }

            subtree = 0;
            if(child[0]) subtree += child[0]->subtree;
            if(child[1]) subtree += child[1]->subtree;
        }
    }

    // Z such that s XOR Z is max
    ll max_xor(ll s, int idx = MAX_DEPTH)
    {
        if(idx < 0) return 0;
        ll c = (s >> idx) & 1;
        if(child[c ^ 1]) return child[c ^ 1]->max_xor(s, idx - 1) | ((c ^ 1) << idx);
        else if(child[c]) return child[c]->max_xor(s, idx - 1) | (c << idx);
        else assert(false);
    }

    // Z such that s XOR Z is min
    ll min_xor(ll s, int idx = MAX_DEPTH)
    {
        if(idx < 0) return 0;
        ll c = (s >> idx) & 1;
        if(child[c]) return child[c]->min_xor(s, idx - 1) | (c << idx);
        else if(child[c ^ 1]) return child[c ^ 1]->min_xor(s, idx - 1) | ((c ^ 1) << idx);
        else assert(false);
    }

    // number of Z such that
    // s XOR Z >= lo, ge -> greater than or equal
    int ge(int s, int lo, int idx = MAX_DEPTH)
    {
        if(idx < 0) return subtree;
        int A = (lo >> idx) & 1;
        int c = (s >> idx) & 1;
        int ans = 0;
        if(A == 0)
        {
            if(child[c]) ans += child[c]->ge(s, lo, idx - 1);
            if(child[c ^ 1]) ans += child[c ^ 1]->subtree;
        }
        else
        {
            if(child[c ^ 1]) ans += child[c ^ 1]->ge(s, lo, idx - 1);
        }
        return ans;
    }

    // number of Z such that
    // s XOR Z <= hi, le -> less than or equal
    int le(int s, int hi, int idx = MAX_DEPTH)
    {
        if(idx < 0) return subtree;
        int B = (hi >> idx) & 1;
        int c = (s >> idx) & 1;
        int ans = 0;
        if(B == 0)
        {
            if(child[c]) ans += child[c]->le(s, hi, idx - 1);
        }
        else
        {
            if(child[c]) ans += child[c]->subtree;
            if(child[c ^ 1]) ans += child[c ^ 1]->le(s, hi, idx - 1);
        }
        return ans;
    }
    
    // number of Z such that
    // lo <= s XOR Z <= hi
    int get_range(int s, int lo, int hi, int idx = MAX_DEPTH)
    {
        if(idx < 0) return subtree;
        int c = (s >> idx) & 1;
        int A = (lo >> idx) & 1, B = (hi >> idx) & 1;
        int ans = 0;
        if(A == B && child[A ^ c]) ans = child[A ^ c]->dfs(s, lo, hi, idx - 1);
        if(A < B)
        {
            if(child[c]) ans += child[c]->ge(s, lo, idx - 1);
            if(child[c ^ 1]) ans += child[c ^ 1]->le(s, hi, idx - 1);
        }
        return ans;
    }
};