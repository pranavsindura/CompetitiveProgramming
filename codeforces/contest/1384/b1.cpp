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

int depth[105];
int off[300];
int n, k, l;

int dp[105][205][305];

bool rec(int i, int t, int stayed)
{

    if(stayed > 2 * k)
        return false;

    if(i == n)
        return true;

    if(depth[i] + off[t % (2 * k)] > l)
        return false;

    int &ret = dp[i][t][stayed];
    if(~ret)
        return ret;

    bool choice1 = rec(i + 1, t + 1, 0);
    bool choice2 = rec(i, t + 1, stayed + 1);
    return ret = (choice1 || choice2);
}

void cp()
{
    cin >> n >> k >> l;
    for(int i = 0; i < n; i++)
        cin >> depth[i];

    bool ok = false;

    int p = 0;
    for(int t = 0; t <= k; t++)
        off[p++] = t;
    for(int t = k - 1; t > 0; t--)
        off[p++] = t;

    clr(dp, -1);
    for(int t = 0; t <= 2 * k; t++)
        ok |= rec(0, t, 0);

    cout << (ok ? "Yes\n" : "No\n");
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}