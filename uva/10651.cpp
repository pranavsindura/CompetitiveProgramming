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
const int MAXN = 1e6 + 5;
using namespace std;

#define M 12

int dp[1 << M];

int solve(bitset<M> mask)
{
    int &ret = dp[mask.to_ulong()];
    if(~ret)
        return ret;
    int ans = mask.count();
    for(int i = 0; i < M - 2; i++)
    {
        if(!mask[i] && mask[i + 1] && mask[i + 2])
        {
            bitset<M> nmask = mask;
            nmask[i] = 1, nmask[i + 2] = 0, nmask[i + 1] = 0;
            ans = min(ans, solve(nmask));
        }
        if(mask[i] && mask[i + 1] && !mask[i + 2])
        {
            bitset<M> nmask = mask;
            nmask[i] = 0, nmask[i + 2] = 1,  nmask[i + 1] = 0;
            ans = min(ans, solve(nmask));
        }
    }
    return ret = ans;
}

void cp()
{
    string s;
    cin >> s;
    int mask = 0;
    for(char x : s)
        mask <<= 1, mask |= (x == 'o');
    cout << solve(bitset<M>(mask)) << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    clr(dp, -1);
    while(t--)
    {
        cp();
    }
    return 0;
}