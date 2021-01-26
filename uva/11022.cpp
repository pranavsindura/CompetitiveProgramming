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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
string s;

int dp[85][85];

int solve(int i, int j)
{
    if(i == j)
        return 1;

    int &ret = dp[i][j];
    if(~ret)
        return ret;
    
    int ans = 100;

    string t;
    for(int k = i; k <= j; k++)
        t += s[k];
    int n = j - i + 1;
    vector<int> failure(n);
    for(int a = 1, k = 0; a < n; a++)
    {
        while(k && t[a] != t[k])
            k = failure[k - 1];
        if(t[a] == t[k])
            k++;
        failure[a] = k;
    }
    int rep = failure.back();
    if(rep && n % (n - rep) == 0)
        ans = solve(i, i + (n - rep) - 1);
    else
        ans = n;
    for(int k = i; k < j; k++)
        ans = min(ans, solve(i, k) + solve(k + 1, j));
    return ret = ans;
}

void cp()
{
    for(int i = 0; i < ln(s); i++)
        for(int j = 0; j < ln(s); j++)
            dp[i][j] = -1;

    int ans = solve(0, ln(s) - 1);
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(cin >> s && s[0] != '*')
    {
        cp();
    }
    return 0;
}