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
int n;
string s;
int dp[100005][3];
int rec(int i, int k)
{
    if(~dp[i][k])
        return dp[i][k];
    if(i == n)
        return 0;
    int res = 0;
    if(k == 0)
    {
        // no flip yet
        //consider flip
        if(s[i] == s[i - 1])
            res = max(res, 1 + rec(i + 1, 1));
        else
            res = max(res, rec(i + 1, 1));
        //go on
        if(s[i] == s[i - 1])
            res = max(res, rec(i + 1, 0));
        else
            res = max(res, 1 + rec(i + 1, 0));
    }
    else if(k == 1)
    {
        // flip started

        //end flip
        if(s[i] == s[i - 1])
            res = max(res, 1 + rec(i + 1, 2));
        else
            res = max(res, rec(i + 1, 2));
        //go on
        if(s[i] == s[i - 1])
            res = max(res, rec(i + 1, 1));
        else
            res = max(res, 1 + rec(i + 1, 1));
    }
    else
    {
        //flip ended
        //go on
        if(s[i] == s[i - 1])
            res = max(res, rec(i + 1, 2));
        else
            res = max(res, 1 + rec(i + 1, 2));
    }
    return dp[i][k] = res;
}

void cp()
{
    cin >> n >> s;
    clr(dp, -1);
    cout << rec(1, 0) + 1;
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