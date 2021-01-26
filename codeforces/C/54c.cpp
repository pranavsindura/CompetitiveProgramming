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
const int MAXN = 1e3 + 5;

ll start_with_one[MAXN], total[MAXN];
int atleast, n;

double dp[MAXN][MAXN];

double solve(int i, int picked)
{
    if(i == n)
        return (picked >= atleast);

    double &ret = dp[i][picked];
    if(fabs(ret + 1) > eps)
        return ret;

    double ans = 0;
    ans += double(start_with_one[i]) / double(total[i]) * solve(i + 1, picked + 1);
    ans += double(total[i] - start_with_one[i]) / double(total[i]) * solve(i + 1, picked);
    return ret = ans;
}

void cp()
{
    int k;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for(auto &x : arr)
        cin >> x.ff >> x.ss;
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        ll l = arr[i].ff, r = arr[i].ss;
        total[i] = r - l + 1;
        ll p = 1;
        for(int j = 0; j <= 18; j++)
        {
            ll a = p;
            ll b = 2 * p - 1;
            a = max(a, l);
            b = min(b, r);
            if(a <= b)
                start_with_one[i] += b - a + 1;
            p *= 10;
        }
    }
    atleast = (n * k + 100 - 1) / 100;

    clr(dp, -1);
    dblout(15);
    cout << solve(0, 0) << endl;
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