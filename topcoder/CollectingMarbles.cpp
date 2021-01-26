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

class CollectingMarbles
{
public:
    int mostMarbles(vector <int>, int, int);
};
int n, m, cap;
vector<int> arr;
int dp[13][1 << 13];
int solve(int i, int mask)
{
    if(i == n)
        return 0;

    int &ret = dp[i][mask];
    if(~ret)
        return ret;

    int ans = 0;
    int msk = mask ^ ((1 << m) - 1);
    for(int nmask = msk; nmask; nmask = (nmask - 1)&msk)
    {
        int sum = 0;
        int cnt = 0;
        for(int j = 0; j < m; j++)
            if((nmask >> j) & 1)
                sum += arr[j], cnt++;
        if(sum <= cap)
            ans = max(ans, cnt + solve(i + 1, mask | nmask));
    }
    return ret = ans;
}

int CollectingMarbles::mostMarbles(vector<int> _arr, int _cap, int _n)
{
    n = _n, cap = _cap, arr = _arr, m = sz(_arr);
    clr(dp, -1);
    return solve(0, 0);
}

int main()
{
    CollectingMarbles c;
    cout << c.mostMarbles({ 2, 2, 2, 2, 2 }, 5, 2) << endl;
    return 0;
}