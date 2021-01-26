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
const int MAXN = 1e4 + 5;
string s;
int dp[MAXN][4];
map<string, bool> ans;

void solve(int i, int last)
{
    int &ret = dp[i][last];
    if(~ret)
        return;
    ret = 1;
    string prev;
    for(int j = 0; j < last; j++)
        prev += s[i + j + 1];
    // try 2
    if(i - 2 >= 4)
    {
        string me;
        me += s[i - 1];
        me += s[i];
        if(me != prev)
            ans[me], solve(i - 2, 2);
    }

    // try 3
    if(i - 3 >= 4)
    {
        string me;
        me += s[i - 2];
        me += s[i - 1];
        me += s[i];
        if(me != prev)
            ans[me], solve(i - 3, 3);
    }
}

void cp()
{
    cin >> s;
    clr(dp, -1);
    solve(ln(s) - 1, 0);
    cout << sz(ans) << endl;
    for(auto &x : ans)
        cout << x.ff << endl;
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