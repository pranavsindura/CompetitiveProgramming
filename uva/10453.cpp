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
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e3 + 5;
int dp[MAXN][MAXN];
string s;
int make_palin(int i, int j)
{
    if(~dp[i][j])
        return dp[i][j];
    if(i >= j)
        return dp[i][j] = 0;
    else
    {
        if(s[i] == s[j])
        {
            return dp[i][j] = make_palin(i + 1, j - 1);
        }
        else
        {
            return dp[i][j] = 1 + min(make_palin(i + 1, j), make_palin(i, j - 1));
        }
    }
}
string ans;

void trace_palin(int i, int j)
{
    if(i > j)
        return;
    else if(i == j)
    {
        ans.pb(s[i]);
    }
    else
    {
        if(s[i] == s[j])
        {
            ans.pb(s[i]);
            trace_palin(i + 1, j - 1);
            ans.pb(s[j]);
        }
        else
        {
            // Add s[i] after j
            int choice1 = make_palin(i + 1, j);
            // Add s[j] before i
            int choice2 = make_palin(i, j - 1);

            int best = min(choice1, choice2);

            if(best == choice1)
            {
                ans.pb(s[i]);
                trace_palin(i + 1, j);
                ans.pb(s[i]);
            }
            else
            {
                ans.pb(s[j]);
                trace_palin(i, j - 1);
                ans.pb(s[j]);
            }
        }
    }
}

void cp()
{
    while(cin >> s)
    {
        clr(dp, -1);
        ans = "";
        int best = make_palin(0, ln(s) - 1);
        trace_palin(0, ln(s) - 1);
        cout << best << " " << ans << endl;
    }
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