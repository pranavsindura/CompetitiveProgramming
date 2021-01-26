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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int dp[71][1 << 19];
int pick[71][2];

int mask(int x)
{
    int ans = 0;
    for(int i = 0; i < sz(prime); i++)
    {
        int c = 0;
        while(x % prime[i] == 0)
            c++, x /= prime[i];
        if(c & 1)
            ans |= (1 << i);
    }
    return ans;

}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    for(int i = 1; i <= 70; i++)
        pick[i][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int t = pick[x][0];
        pick[x][0] = (pick[x][0] + pick[x][1]) % mod;
        pick[x][1] = (pick[x][1] + t) % mod;
    }
    int tmask = 1 << 19;
    dp[0][0] = 1;
    for (int i = 1; i <= 70; i++)
        for (int j = 0; j < tmask; j++)
        {
            dp[i][j] = dp[i - 1][j] * 1LL * pick[i][0] % mod;

            dp[i][j] += dp[i - 1][j ^ mask(i)] * 1LL * pick[i][1] % mod;
            dp[i][j] %= mod;
        }

    cout << (dp[70][0] + mod - 1) % mod;
    return 0;
}