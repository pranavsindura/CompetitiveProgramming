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
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for(int &x : arr)
        cin >> x;

    vector<int> sub;

    int mx = INT_MIN, cnt = 0;
    for(int i = 0; i < sz(arr); i++)
    {
        if(arr[i] > mx)
        {
            if(cnt)
                sub.pb(cnt);
            mx = arr[i];
            cnt = 1;
        }
        else
            cnt++;
    }

    sub.pb(cnt);

    int m = sz(sub);
    bool dp[m + 1][2 * n + 1];
    clr(dp, false);
    dp[0][0] = true;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= 2 * n; j++)
        {
            // use the i-th element to make sum = j
            if(j >= sub[i - 1])
                dp[i][j] |= dp[i - 1][j - sub[i - 1]];
            // or dont use
            dp[i][j] |= dp[i - 1][j];
        }
    }
    cout << (dp[m][n] ? "YES\n" : "NO\n");
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