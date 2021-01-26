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

int m, s;

int dp[105][905];

bool solve(int pos, int sum)
{
    if(pos == m)
        return sum == 0;

    int &ret = dp[pos][sum];
    if(~ret)
        return ret;

    bool ans = false;
    for(int i = (pos == 0); i < 10; i++)
        if(sum >= i)
            ans |= solve(pos + 1, sum - i);
    return ret = ans;
}

string mx, mn;

void trace_max(int pos, int sum)
{
    if(pos == m)
        return;

    for(int i = 9; i >= (pos == 0); i--)
    {
        if(sum >= i)
        {
            if(solve(pos + 1, sum - i))
            {
                mx += char(48 + i);
                trace_max(pos + 1, sum - i);
                return;
            }
        }
    }
}

void trace_min(int pos, int sum)
{
    if(pos == m)
        return;

    for(int i = (pos == 0); i < 10; i++)
    {
        if(sum >= i)
        {
            if(solve(pos + 1, sum - i))
            {
                mn += char(48 + i);
                trace_min(pos + 1, sum - i);
                return;
            }
        }
    }
}

void cp()
{
    cin >> m >> s;
    if(m == 1 && s == 0)
    {
        cout << "0 0" << endl;
        return;
    }
    clr(dp, -1);
    solve(0, s);
    trace_max(0, s);
    trace_min(0, s);
    if(!mx.empty() && !mn.empty())
        cout << mn << " " << mx << endl;
    else
        cout << "-1 -1\n";
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