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
const int MAXN = 1e5 + 5;

bool dp[2][MAXN];
bool can_make[MAXN];

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    dp[0][0] = 1;
    dp[0][arr[0]] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < MAXN; j++)
        {
            if(j - arr[i] >= 0)
                dp[1][j] = dp[0][j - arr[i]];
            dp[1][j] |= dp[0][j];
        }
        dp[1][arr[i]] = 1;
        for(int j = 0; j < MAXN; j++)
            dp[0][j] = dp[1][j], dp[1][j] = 0;
    }

    vector<int> can;
    for(int i = 1; i < MAXN; i++)
        if(dp[0][i])
            can.pb(i);
    cout << sz(can) << endl;
    for(int x : can)
        cout << x << " ";
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