#include <bits/stdc++.h>
#define ll        long long int
#define ld        long double
#define pi        pair<int,int>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl
#define clr(x,v)  memset(x, v, sizeof(x))
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1LL << 30;
const int MAXN = 1e5 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> pos(n + 1, vector<int>(1, -1));
    for(int i = 0; i < n; i++)
        cin >> arr[i], pos[arr[i]].pb(i);
    for(int i = 0; i <= n; i++)
        pos[i].pb(n);
    int best = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        if(sz(pos[i]) <= 2) continue;
        int sum = 0;
        for(int j = 1; j < sz(pos[i]); j++)
            sum += (pos[i][j] - pos[i][j - 1] - 1 > 0);
        best = min(best, sum);
    }
    cout << best << endl;
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

