#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e5 + 5;
map<string, int> idx;
int counter;
int get_idx(string &s)
{
    if(idx.count(s))
        return idx[s];
    else
        return idx[s] = counter++;
}

int parent[MAXN];
int size[MAXN];

void make_set()
{
    iota(parent, parent + MAXN, 0);
    fill(size, size + MAXN, 1);
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
    int u = find_set(a), v = find_set(b);
    if(size[u] < size[v])
        swap(u, v);
    if(u != v)
        parent[v] = u, size[u] += size[v];
    return u != v;
}

void cp()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        get_idx(s);
    }

    make_set();

    // u, opposite of u -> u+n
    while(m--)
    {
        string x, y;
        int t, a, b;
        cin >> t >> x >> y;
        a = get_idx(x), b = get_idx(y);

        bool ok = true;

        if(t == 1)// same
        {
            if(find_set(a) == find_set(b + n))
                ok = false;
            else
                union_set(a, b), union_set(a + n, b + n);
        }
        else// opp
        {
            if(find_set(a) == find_set(b))
                ok = false;
            else
                union_set(a, b + n), union_set(a + n, b);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    while(q--)
    {
        int t = 3;
        string x, y;
        cin >> x >> y;

        int a = get_idx(x), b = get_idx(y);

        if(find_set(a) == find_set(b))
            t = 1;
        else if(find_set(a) == find_set(b + n))
            t = 2;

        cout << t << endl;
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