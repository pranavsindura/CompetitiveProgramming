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
int n, x;
unsigned ll dp[25][150];
bool vis[25][150];
unsigned ll solve(int i, int sum)
{
    if(i == n)
        return sum >= x;
    if(vis[i][sum])
        return dp[i][sum];
    vis[i][sum] = 1;
    unsigned ll ans = 0;
    for(int j = 1; j <= 6; j++)
        ans += solve(i + 1, sum + j);
    return dp[i][sum] = ans;
}

unsigned ll gcd(unsigned ll a, unsigned ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void cp()
{
    while(cin >> n >> x && n + x)
    {
        unsigned ll total = 1;
        for(int i = 0; i < n; i++)
            total *= 6ULL;
        clr(vis, false);
        clr(dp, 0);
        unsigned ll actual = solve(0, 0);
        unsigned ll g = gcd(actual, total);
        if(actual == total)
        {
            cout << 1 << endl;
        }
        else if(actual == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            actual /= g, total /= g;
            cout << actual << "/" << total << endl;
        }
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