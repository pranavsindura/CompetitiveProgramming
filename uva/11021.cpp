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

double fpow(double x, int y)
{
    double res = 1;
    while(y > 0)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void cp()
{
    int n, m, k;
    cin >> n >> k >> m;
    vector<double> prob(n);
    for(double &x : prob)
        cin >> x;
    double dp[m];
    clr(dp, 0);
    dp[0] = prob[0];
    for(int i = 1; i < m; i++)
        for(int j = 0; j < n; j++)
            dp[i] += prob[j] * fpow(dp[i - 1], j);
    cout << setprecision(7) << fixed << fpow(dp[m - 1], k) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cp();
    }
    return 0;
}