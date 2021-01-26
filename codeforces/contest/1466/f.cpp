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

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const int mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;

void cp()
{
    int n, m;
    cin >> n >> m;

    vector<set<int>> mask(n);
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            x--;
            mask[i].insert(x);
        }
    }
    
    vector<bool> basis_idx(m);
    vector<int> keep;
    vector<vector<int>> basis(m);

    int sz = 0;
    for(int i = 0; i < n; i++)
    {
        while(!mask[i].empty())
        {
            int p = *mask[i].begin();
            if(!basis_idx[p]) // no vector, put into basis
                basis[p] = vector<int>(all(mask[i])), sz++, keep.push_back(i), basis_idx[p] = 1;
            for(int x : basis[p])
                if(mask[i].count(x)) mask[i].erase(x);
                else mask[i].insert(x);
        }
    }

    int ans = 1;
    for(int i = 0; i < sz; i++) ans = (ans * 2) % mod;
    cout << ans << " " << sz << endl;
    for(int idx : keep)
        cout << idx + 1 << " ";
    cout << endl;
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

