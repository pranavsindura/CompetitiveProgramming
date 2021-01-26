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
const int MAXN = 1e5 + 5;

int arr[MAXN];
ll dp[MAXN][6][2];
int n, k, z;

ll solve(int i, int off, bool last_left)
{
    if(i == k)
        return 0;
    else
    {
        ll &ret = dp[i][off][last_left];
        if(~ret)
            return ret;

        int pos = i - 2 * off;
        if(pos == 0)
        {
            return ret = arr[pos + 1] + solve(i + 1, off, 0);
        }
        else if(pos == n - 1)
        {
            ll c = 0;
            if(off < z && !last_left)
                c = arr[pos - 1] + solve(i + 1, off + 1, 1);
            return ret = c;
        }
        else
        {
            ll c1 = 0, c2 = 0;
            if(off < z && !last_left)
                c1 = arr[pos - 1] + solve(i + 1, off + 1, 1);
            c2 = arr[pos + 1] + solve(i + 1, off, 0);
            return ret = max(c1, c2);
        }
    }
}

void cp()
{
    cin >> n >> k >> z;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 6; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = -1;
            
    cout << arr[0] + solve(0, 0, 0) << endl;
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