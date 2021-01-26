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

int n;
char A[MAXN][MAXN], B[MAXN][MAXN];

void vxor(int j)
{
    for(int i = 0; i < n; i++)
        A[i][j] = A[i][j] == '0' ? '1' : '0';
}

void hxor(int i)
{
    for(int j = 0; j < n; j++)
        A[i][j] = A[i][j] == '0' ? '1' : '0';
}

void cp()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> B[i][j];

    bool ok = true;

    for(int j = 0; j < n; j++)
        if(B[0][j] != A[0][j])
            vxor(j);

    for(int i = 1; i < n; i++)
    {
        bool same = true;
        for(int j = 0; j < n; j++)
            if(B[i][j] != A[i][j])
                same = false;
        if(same) continue;
        hxor(i);
        same = true;
        for(int j = 0; j < n; j++)
            if(B[i][j] != A[i][j])
                same = false;
        if(same) continue;
        ok = false;
    }

    cout << (ok ? "YES\n" : "NO\n");
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

