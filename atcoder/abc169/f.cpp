#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const ll mod = 998244353;
const double PI = acos(-1.0);
const int MAXN = 3e3 + 5;
ll dp[MAXN][MAXN];
int arr[MAXN];
int n, s;

ll rec(int pos, int sum)
{
    if(pos == n)
    {
        if(sum == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(arr[pos] > sum)
            return rec(pos + 1, sum) % mod;
        else
            return (rec(pos + 1, sum) + rec(pos + 1, sum - arr[pos])) % mod;
    }
}

void cp()
{
    clr(dp, -1);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << rec(0, s);
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