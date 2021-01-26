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

ll ways[MAXN][MAXN];
char arr[MAXN][MAXN];

void cp()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(arr[0][0] == '.')
        ways[0][0] = 1;

    for(int i = 1; i < n; i++)
        if(arr[i][0] == '.')
            ways[i][0] += ways[i - 1][0];

    for(int i = 1; i < n; i++)
        if(arr[0][i] == '.')
            ways[0][i] += ways[0][i - 1];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            if(arr[i][j] == '.')
                ways[i][j] = (ways[i][j] + (ways[i - 1][j] % mod + ways[i][j - 1] % mod) % mod) % mod;

    cout << ways[n - 1][n - 1] % mod;
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