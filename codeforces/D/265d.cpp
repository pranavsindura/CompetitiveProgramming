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
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
using namespace std;
vector<int> prime;
int lp[MAXN];
int last[MAXN];
int dp[MAXN];
void init()
{
    lp[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!lp[i])
            lp[i] = i, prime.pb(i);
        for(int j = 0; j < sz(prime) && i * 1LL * prime[j] < 1LL * MAXN; j++)
        {
            lp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    clr(last, -1);
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        while(arr[i] > 1)
        {
            int x = lp[arr[i]];
            if(last[x] != -1)
                dp[i] = max(dp[i], dp[last[x]] + 1);
            last[x] = i;
            while(arr[i] % x == 0)
                arr[i] /= x;
        }
    }
    int ans = *max_element(dp, dp + n);
    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    init();
    while(t--)
    {
        cp();
    }
    return 0;
}