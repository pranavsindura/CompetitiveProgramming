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
int dp[105][500 * 105];
void cp()
{
    int n, total = 0;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 0; i < n; i++)
        cin >> arr[i + 1], total += arr[i + 1];
    int half = total / 2;
    //consider it now a knapsack problem, subset so that we can get closest to half
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= half; j++)
        {
            if(i == 0 || j == 0 )
            {
                dp[i][j] = 0;
                continue;
            }
            if(arr[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], arr[i] + dp[i - 1][j - arr[i]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    //now difference will be total - 2*dp[n][half]
    cout << total - 2 * dp[n][half] << endl;
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