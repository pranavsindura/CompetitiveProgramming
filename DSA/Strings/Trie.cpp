// Simple Trie Format
// Fixed array of children
// For more complicated Trie, we can use a map of char->trie ptr, or string->trie ptr

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

    void dfs()
    {

    }
};