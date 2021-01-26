// DSU by Size
int parent[MAXN], sz[MAXN];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(sz, sz + n, 1);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(sz[a] < sz[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, sz[a] += sz[b];
    return a != b;
}



// DSU by Rank or Depth
int parent[MAXN], rank[MAXN];
void make_set(int n)
{
    iota(parent, parent + n, 0);
    fill(rank, rank + n, 0);
}
int find_set(int v)
{
    if(v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}
bool union_set(int a, int b)
{
    a = find_set(a), b = find_set(b);
    if(rank[a] < rank[b])
        swap(a, b);
    if(a != b)
        parent[b] = a, rank[a] += rank[a] == rank[b];
    return a != b;
}


/*  
    To use a property of a node u (or its parent) always use find_set(u) 's property
    instead of u's property as path compression is not guaranteed

    components = 0
    for u in range(n):
        if u == find_set(u): // instead of u == par[u]
            components++
*/