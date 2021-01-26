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
int n, max_turn;
vector<int> arr;
double dp[75][1 << 7];
double solve(int turn, int mask)
{
    if(turn > max_turn)
        return 1;
    if(mask == ((1 << n) - 1))
        return 1;

    double &ret = dp[turn][mask];
    if(fabs(ret + 1) > eps)
        return ret;

    double prob = 0;

    int msk = mask ^ ((1 << n) - 1);
    for(int nmask = msk; nmask; nmask = (nmask - 1)&msk)
    {
        double me = 1;
        for(int i = 0; i < n; i++)
        {
            if((nmask >> i) & 1)
            {
                if(arr[i] < turn)
                    me = 0;
                else if(arr[i] > turn)
                    me *= 1.0 / double(arr[i] - turn);
            }
            else if(((mask >> i) & 1) == 0)
            {
                if(arr[i] <= turn)
                    me *= 1;
                else
                    me *= double(arr[i] - turn - 1) / double(arr[i] - turn);
            }
        }
        me *= solve(turn + 1, mask | nmask);
        prob += me;
    }
    return ret = prob;
}

void cp()
{
    cin >> n;
    max_turn = 0;
    arr.clear();
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.pb(ln(s));
        max_turn += ln(s);
    }
    clr(dp, -1);
    cout << setprecision(3) << fixed << solve(0, 0) << endl;
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