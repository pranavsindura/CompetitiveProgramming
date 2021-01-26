#include <bits/stdc++.h>
using namespace std;

void make_set(int v, int parent[], int size[])
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v, int parent[])
{
    if (parent[v] == v)
    {
        return v;
    }
    else
    {
        return parent[v] = find_set(parent[v], parent);
    }
}

int union_sets(int a, int b, int parent[], int size[])
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
pair<int, int> cycle(vector<pair<int, int>> edges, int parent[], int size[], vector<pair<int, int>> degree)
{
    pair<int, int> node;
    long long int s = INT_MAX, ns = INT_MAX;
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        int x = find_set(it->first, parent);
        int y = find_set(it->second, parent);
        if (x == y)
        {
            //return {x, y};
            int a = it->first;
            int b = it->second;
            if (degree[a].second < s || degree[b].second < ns || degree[a].second < ns || degree[b].second < s)
            {
                node = {a, b};
                s = degree[a].second;
                ns = degree[b].second;
            }
        }
        else
        {
            union_sets(x, y, parent, size);
        }
    }
    return node;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        scanf("%d %d", &n, &m);
        vector<int> adj[n + 1];
        vector<pair<int, int>> degree, edges;
        int parent[n + 1], size[n + 1];
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back({a, b});
        }
        if (m % 2 == 0)
        {
            printf("1\n");
            for (int i = 1; i <= n; i++)
            {
                printf("1 ");
            }
            printf("\n");
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                degree.push_back({i, adj[i].size()});
            }
            int node = 0;
            for (int i = 0; i < degree.size(); i++)
            {
                if (degree[i].second % 2 != 0)
                {
                    node = degree[i].first;
                    break;
                }
            }
            if (node)
            {
                printf("2\n");
                for (int i = 1; i <= n; i++)
                {
                    if (i != node)
                        printf("1 ");
                    else
                        printf("2 ");
                }
                printf("\n");
            }
            else
            {
                pair<int, int> c;
                for (int i = 1; i <= n; i++)
                    make_set(i, parent, size);
                c = cycle(edges, parent, size, degree);
                printf("3\n");
                for (int i = 1; i <= n; i++)
                {
                    if (i != c.second && i != c.first)
                        printf("1 ");
                    else if (i == c.first)
                        printf("2 ");
                    else if (i == c.second)
                        printf("3 ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}