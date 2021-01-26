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
const int MAXN = 1e3 + 5;
ll C[MAXN][MAXN];

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    for(int i = 0; i < MAXN; i++)
        C[i][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            C[i][j] = (C[i - 1][j] % mod + C[i - 1][j - 1] % mod) % mod;

    ll ans = 1;
    int m = 0;
    for(int x : arr)
    {
        ans = (ans * C[m + x - 1][x - 1]) % mod;
        m += x;
    }
    cout << ans;
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