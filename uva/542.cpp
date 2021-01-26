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

double prob[16][16];

double dp[16][16][16];

double solve(int lo, int hi, int winner)
{
    if(lo == hi)
        return 1;

    double &ret = dp[lo][hi][winner];
    if(fabs(ret + 1) > eps)
        return ret;

    int mid = (lo + hi) / 2;
    double ans = 0;
    if(winner <= mid)
    {
        for(int j = mid + 1; j <= hi; j++)
            ans += prob[winner][j] * solve(mid + 1, hi, j);
        ans *= solve(lo, mid, winner);
    }
    else
    {
        for(int j = lo; j <= mid; j++)
            ans += prob[winner][j] * solve(lo, mid, j);
        ans *= solve(mid + 1, hi, winner);
    }
    return ret = ans;
}

void cp()
{
    vector<string> name(16);
    for(string &x : name)
        cin >> x;
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++)
            cin >> prob[i][j], prob[i][j] /= 100.0;
    double ans[16] = {0};
    clr(dp, -1);
    for(int i = 0; i < 16; i++)
        ans[i] = solve(0, 15, i) * 100.0;
    for(int i = 0; i < 16; i++)
        cout << setw(10) << left << name[i] << " p=" << setprecision(2) << fixed << ans[i] << "%\n";
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