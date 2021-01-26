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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int r, n;
    cin >> r >> n;
    vector<vector<int>> arr(n + 1);
    arr[0] = {1, 1, 0};
    for(int i = 1; i <= n; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        arr[i] = {x, y, t};
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i - 1; j >= 0 && i - j < 2 * r; j--)
        {
            int dist = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]);
            int have_time = arr[i][2] - arr[j][2];
            if(dist <= have_time && dp[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        if(i - 2 * r >= 0)
            dp[i] = max(dp[i], dp[i - 2 * r] + 1);
        if(i - 2 * r >= 0)
            dp[i - 2 * r + 1] = max(dp[i - 2 * r + 1], dp[i - 2 * r]);
    }

    cout << *max_element(all(dp)) - 1 << endl;
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