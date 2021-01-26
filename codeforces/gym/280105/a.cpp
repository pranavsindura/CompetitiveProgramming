#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);
int dp[4005][4005];
void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    set<int> s(all(arr));
    vector<int> distinct(all(s));
    map<int, int> compress;
    for(int i = 0; i < sz(distinct); i++)
        compress[distinct[i]] = i;
    for(int &x : arr)
        x = compress[x]; 
    int ans = min(n, 2);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < sz(distinct); j++)
        {
            dp[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i][arr[j]] = max(dp[i][arr[j]], dp[j][arr[i]] + 1);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < sz(distinct); j++)
        {
            ans = max(ans, dp[i][j]);
        }
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