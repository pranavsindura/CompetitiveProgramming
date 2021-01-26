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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);
int arr[55];
int dp[55][55];
int solve(int i, int j, int st, int en)
{
    if(i > j || st > en)
        return 0;
    if(i == j)
        return en - st;
    else
    {
        if(~dp[i][j])
            return dp[i][j];
        int ret = 10000005;
        for(int k = i; k <= j; k++)
        {
            // make cut at k
            ret = min(ret, solve(i, k - 1, st, arr[k]) + solve(k + 1, j, arr[k], en));
        }
        return dp[i][j] = ret + en - st;
    }
}
void cp()
{
    int l;
    while(cin >> l && l)
    {
        clr(dp, -1);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "The minimum cutting is " << solve(0, n - 1, 0, l) << "." << endl;
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