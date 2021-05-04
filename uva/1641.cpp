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
const int MAXN = 1e5 + 5;

char arr[105][105];

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
bool is_connected(int a, int b)
{
    return find_set(a) == find_set(b);
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

#define get(x, y) 4 * ((x) * m + y)

void cp()
{
    int n, m;
    auto valid = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        make_set(n * m * 4);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(valid(i + 1, j))
                    union_set(get(i, j) + 3, get(i + 1, j) + 1);
                if(valid(i - 1, j))
                    union_set(get(i, j) + 1, get(i - 1, j) + 3);
                if(valid(i, j + 1))
                    union_set(get(i, j) + 2, get(i, j + 1) + 0);
                if(valid(i, j - 1))
                    union_set(get(i, j) + 0, get(i, j - 1) + 2);
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] != '/')
                {
                    union_set(get(i, j) + 1, get(i, j) + 2);
                    union_set(get(i, j) + 0, get(i, j) + 3);
                }
                if(arr[i][j] != '\\')
                {
                    union_set(get(i, j) + 0, get(i, j) + 1);
                    union_set(get(i, j) + 2, get(i, j) + 3);
                }
            }
        int ans = -1;
        for(int i = 0; i < n && ans == -1; i++)
            for(int j = 0; j < m && ans == -1; j++)
                if(arr[i][j] == '/')
                    ans = sz[find_set(get(i, j) + 2)];
        ans /= 4;
        cout << ans << endl;


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
