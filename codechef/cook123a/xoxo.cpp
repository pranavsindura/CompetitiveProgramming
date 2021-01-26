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
const int MAXN = 3e5 + 5;
int dp[MAXN];
void init()
{
	for(int i=0;i<MAXN;i++)
		dp[i] = 1e7;
    // form dp
    for(int i = 1; i < MAXN; i++)
        for(int j = i; j < MAXN; j += i)
            dp[j] = min(dp[j], i + j / i);

    // minimise dp
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j <= sqrt(i); j++)
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
}

void cp()
{
    int n, k, x;
    cin >> n >> k >> x;
    bool ok = dp[k] <= n;
    cout << (ok ? "YES\n" : "NO\n");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}