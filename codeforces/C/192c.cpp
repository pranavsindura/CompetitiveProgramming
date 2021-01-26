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
    int dp[26][26] = {0};
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int a = s[0] - 'a';
        int b = s.back() - 'a';
        for(int c = 0; c < 26; c++)
        {
            if(dp[c][a] > 0)
                dp[c][b] = max(dp[c][b], dp[c][a] + ln(s));
        }
        dp[a][b] = max(dp[a][b], ln(s));
    }
    int mx = 0;
    for(int i = 0; i < 26; i++)
        mx = max(mx, dp[i][i]);
    cout << mx;
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