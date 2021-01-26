#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int parent[10000000], size[10000000];
void make_set(int v)
{
    parent[v] = -1;
    size[v] = 1;
}

int find_set(int v)
{
    return parent[v];
    // if (v == parent[v])
    // {
    //     return v;
    // }
    // else
    // {
    //     return parent[v] = find_set(parent[v]);
    //     // return find_set(parent[v]);
    // }
}

int union_sets(int a, int b)
{
    // a = find_set(a);
    // b = find_set(b);
    // if (a != b || (a == -1 && b == -1))
    // {
    // if (size[a] < size[b])
    //     swap(a, b);
    // parent[b] = a;
    // size[a] += size[b];
    // }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, a, b;
        cin >> n >> q;
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++)
        {
            make_set(i + 1);
        }
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            union_sets(a, b);
        }
        // for (int i = 1; i <= n; i++)
        //     cout << parent[i] << " ";
        // cout << endl;
        while (q--)
        {
            int x, y;
            ll S, H;
            cin >> x >> y >> S >> H;
            int px = x, py = y;
            bool flag = true;
            ll c=1;
            while (true)
            {
                if (H <= 0 || S <= 0)
                {
                    flag = false;
                    break;
                }
                if (px == -1 || py == -1)
                {
                    flag = false;
                    break;
                }
                if (px == 1 && py == 1)
                {
                    flag = true;
                    break;
                }
                else if (px == py && px != 1)
                {
                    S = (S + H) / 2;
                    H = S;
                    S-=c, H-=c;
                    px = find_set(px);
                    py = find_set(py);
                }
                else if (px == 1 && py != 1)
                {
                    py = find_set(py);
                    H-=c;
                }
                else if (px != 1 && py == 1)
                {
                    px = find_set(px);
                    S-=c;
                }
                else
                {
                    px = find_set(px);
                    py = find_set(py);
                    S-=c;
                    H-=c;
                }
                c++;
            }
            if (flag)
            {
                cout << S + H << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}