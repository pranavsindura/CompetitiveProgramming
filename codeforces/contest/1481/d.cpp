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
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e3 + 5;

char edge[MAXN][MAXN];

void cp()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> edge[i];
    if(m & 1)
    {
        cout << "YES\n";
        for(int i = 0; i < m + 1; i++)
            cout << i % 2 + 1 << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(i != j && edge[i][j] == edge[j][i])
                {
                    cout << "YES\n";
                    for(int k = 0; k < m + 1; k++)
                        cout << (k % 2 ? i + 1 : j + 1) << " ";
                    cout << endl;
                    return;
                }

        for (int i = 0; i < n; i++)
        {
            for(char c = 'a'; c <= 'b'; c++)
            {
                vector<int> L, R;
                for(int j = 0; j < n; j++)
                {
                    if(i == j) continue;
                    if(edge[j][i] == c) L.pb(j);
                    if(edge[i][j] == c) R.pb(j);
                }
                while(sz(L) > 2) L.pop_back();
                while(sz(R) > 2) R.pop_back();
                for(int a : L)
                    for(int b : R)
                    {
                        if(a == b) continue;
                        vector<int> path;
                        if((m / 2) % 2) path = {a, i, b, i};
                        else path = {i, b, i, a};
                        cout << "YES\n";
                        for(int k = 0; k < m + 1; k++)
                            cout << path[k % 4] + 1 << " ";
                        cout << endl;
                        return;
                    }
            }
        }
        cout << "NO\n";
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
