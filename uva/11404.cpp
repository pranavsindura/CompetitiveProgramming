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
string dp[MAXN][MAXN];
string s;

string solve(int i, int j)
{
    if(ln(dp[i][j]))
        return dp[i][j];
    if(i > j)
        return dp[i][j] = "";
    else if(i == j)
        return dp[i][j] = s[i];
    else
    {
        if(s[i] == s[j])
            return dp[i][j] = s[i] + solve(i + 1, j - 1) + s[j];
        else
        {
            string c1 = solve(i + 1, j);
            string c2 = solve(i, j - 1);
            if(ln(c1) > ln(c2))
                return dp[i][j] = c1;
            else if(ln(c1) < ln(c2))
                return dp[i][j] = c2;
            if(c1 <= c2)
                return dp[i][j] = c1;
            else
                return dp[i][j] = c2;
        }
    }
}

void cp()
{
    while(cin >> s)
    {
        for(int i = 0; i < ln(s); i++)
            for(int j = 0; j < ln(s); j++)
                dp[i][j] = "";
        string ans = solve(0, ln(s) - 1);
        cout << ans << endl;
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